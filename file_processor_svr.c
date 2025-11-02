#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>

#define FIFO_CLIENT_TO_SERVER "/tmp/fifo_c2s"
#define FIFO_SERVER_TO_CLIENT "/tmp/fifo_s2c"
#define MAX_LINE 1024

int count_chars_words(const char *line, int *char_count, int *word_count) {
    *char_count = strlen(line);
    *word_count = 0;
    int in_word = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (isspace(line[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            (*word_count)++;
        }
    }
    return 0;
}

void to_upper(char *line) {
    for (int i = 0; line[i]; i++) line[i] = toupper(line[i]);
}

void to_lower(char *line) {
    for (int i = 0; line[i]; i++) line[i] = tolower(line[i]);
}

void reverse_line(char *line) {
    int len = strlen(line);
    for (int i = 0; i < len/2; i++) {
        char tmp = line[i];
        line[i] = line[len - 1 - i];
        line[len - 1 - i] = tmp;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <count|upper|lower|reverse>\n", argv[0]);
        exit(1);
    }
    const char *mode = argv[1];

    mkfifo(FIFO_CLIENT_TO_SERVER, 0666);
    mkfifo(FIFO_SERVER_TO_CLIENT, 0666);

    int fd_read = open(FIFO_CLIENT_TO_SERVER, O_RDONLY);
    int fd_write = open(FIFO_SERVER_TO_CLIENT, O_WRONLY);

    char line[MAX_LINE];
    int line_num = 0;

    while (1) {
        ssize_t n = read(fd_read, line, MAX_LINE - 1);
        if (n <= 0) break;
        line[n] = '\0';

        if (strcmp(line, "END\n") == 0 || strcmp(line, "END") == 0) {
            break;
        }

        line_num++;
        printf("%d번째 줄 처리 중...\n", line_num);

        char result[MAX_LINE * 2] = {0};
        if (strcmp(mode, "count") == 0) {
            int ccount, wcount;
            count_chars_words(line, &ccount, &wcount);
            sprintf(result, "Line %d: %d chars, %d words\n", line_num, ccount, wcount);
        } else if (strcmp(mode, "upper") == 0) {
            to_upper(line);
            sprintf(result, "%s", line);
        } else if (strcmp(mode, "lower") == 0) {
            to_lower(line);
            sprintf(result, "%s", line);
        } else if (strcmp(mode, "reverse") == 0) {
            reverse_line(line);
            sprintf(result, "%s", line);
        } else {
            sprintf(result, "Unknown mode\n");
        }

        write(fd_write, result, strlen(result));
    }

    close(fd_read);
    close(fd_write);
    unlink(FIFO_CLIENT_TO_SERVER);
    unlink(FIFO_SERVER_TO_CLIENT);

    return 0;
}
