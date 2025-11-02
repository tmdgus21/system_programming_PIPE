#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define FIFO_CLIENT_TO_SERVER "/tmp/fifo_c2s"
#define FIFO_SERVER_TO_CLIENT "/tmp/fifo_s2c"
#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <mode> \n", argv[0]);
        exit(1);
    }

    const char *input_file = argv[1];
    const char *mode = argv[2];

    mkfifo(FIFO_SERVER_TO_CLIENT, 0666);
    mkfifo(FIFO_CLIENT_TO_SERVER, 0666);

    int fd_write = open(FIFO_CLIENT_TO_SERVER, O_WRONLY);
    int fd_read = open(FIFO_SERVER_TO_CLIENT, O_RDONLY);

    FILE *fp = fopen(input_file, "r");
    if (!fp) {
        perror("파일 열기 실패");
        exit(1);
    }

    char line[MAX_SIZE];
    char buf[MAX_SIZE * 2];
    int line_num = 0;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    while (fgets(line, sizeof(line), fp)) {
        line_num++;
        printf("%d번쨰 줄 전송...\n", line_num);
        write(fd_write, line, strlen(line));

        ssize_t n = read(fd_read, buf, sizeof(buf) - 1);
        if ( n > 0) {
            buf[n] = '\0';
            printf("%d번쪠 줄 결과 수신: %s\n", line_num, buf);
        }
    }

    write(fd_write, "END\n", 4);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("=== 처리 통계 ===\n");
    printf("처리 모드: %s\n", mode);
    printf("처리한 줄 수: %d줄\n", line_num);
    printf("소요 시간: %.2f초\n",elapsed);

    fclose(fp);
    close(fd_write);
    close(fd_read);

    return 0;
}
