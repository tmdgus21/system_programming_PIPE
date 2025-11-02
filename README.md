# 프로세스 협력 파일 처리기



### 개요

- 클라이언트-서버 모델을 사용하여 파일의 각 줄 처리

- 클라이언트는 파일의 각 줄을 서버에 전송

- 서버는 지정된 처리 모드에 따라 각 줄을 처리한 후 결과를 클라이언트에 반환

- 처리 모드:

    - count: 문자 수 및 단어 수 계산

    - upper: 대문자로 변환

    - lower: 소문자로 변환

    - reverse: 문자열 뒤집기

- 사용법

```

./file_processor_clnt <input_file> <mode>

```

- <input_file>: 처리할 텍스트 파일의 경로

- <mode>: count, upper, lower, reverse 중 하나



## 실행결과

### 클라이언트: count

```

./file_processor_clnt test.txt count

    1번쨰 줄 전송...
    1번쪠 줄 결과 수신: Line 1: 51 chars, 10 words
    
    2번쨰 줄 전송...
    2번쪠 줄 결과 수신: Line 2: 69 chars, 12 words
    
    3번쨰 줄 전송...
    3번쪠 줄 결과 수신: Line 3: 48 chars, 8 words
    
    4번쨰 줄 전송...
    4번쪠 줄 결과 수신: Line 4: 67 chars, 13 words
    
    5번쨰 줄 전송...
    5번쪠 줄 결과 수신: Line 5: 45 chars, 6 words
    
    6번쨰 줄 전송...
    6번쪠 줄 결과 수신: Line 6: 41 chars, 7 words
    
    7번쨰 줄 전송...
    7번쪠 줄 결과 수신: Line 7: 37 chars, 8 words
    
    8번쨰 줄 전송...
    8번쪠 줄 결과 수신: Line 8: 52 chars, 9 words
    
    9번쨰 줄 전송...
    9번쪠 줄 결과 수신: Line 9: 56 chars, 9 words
    
    10번쨰 줄 전송...
    10번쪠 줄 결과 수신: Line 10: 46 chars, 8 words
    
    === 처리 통계 ===
    처리 모드: count
    처리한 줄 수: 10줄
    소요 시간: 0.00초

```

### 클라이언트: upper

```

./file_processor_clnt test.txt upper

    1번쨰 줄 전송...
    1번쪠 줄 결과 수신: A JOURNEY OF 1000 MILES BEGINS WITH A SINGLE STEP.
    
    2번쨰 줄 전송...
    2번쪠 줄 결과 수신: THE MAN WHO REMOVES A MOUNTAIN BEGINS BY CARRYING AWAY SMALL STONES.
    
    3번쨰 줄 전송...
    3번쪠 줄 결과 수신: CHANGE YOUR THOUGHTS AND YOU CHANGE YOUR WORLD.
    
    4번쨰 줄 전송...
    4번쪠 줄 결과 수신: THE GREAT PLEASURE IN LIFE IS DOING WHAT PEOPLE SAY YOU CANNOT DO.
    
    5번쨰 줄 전송...
    5번쪠 줄 결과 수신: EVERY GREAT ACHIEVEMENT WAS ONCE IMPOSSIBLE.
    
    6번쨰 줄 전송...
    6번쪠 줄 결과 수신: DILIGENCE IS THE MOTHER OF GOOD FORTUNE.
    
    7번쨰 줄 전송...
    7번쪠 줄 결과 수신: THE BUSY BEE HAS NO TIME FOR SORROW.
    
    8번쨰 줄 전송...
    8번쪠 줄 결과 수신: IT TAKES TWENTY YEARS TO MAKE AN OVERNIGHT SUCCESS.
    
    9번쨰 줄 전송...
    9번쪠 줄 결과 수신: THE LAZIEST PEOPLE HAVE THE BIGGEST PLANS FOR TOMORROW.
    
    10번쨰 줄 전송...
    10번쪠 줄 결과 수신: ALL THINGS ARE DIFFICULT BEFORE THEY ARE EASY.
    === 처리 통계 ===
    처리 모드: upper
    처리한 줄 수: 10줄
    소요 시간: 0.00초

```



### 클라이언트: lower

```

./file_processor_clnt test.txt lower

    1번쨰 줄 전송...
    1번쪠 줄 결과 수신: a journey of 1000 miles begins with a single step.
    
    2번쨰 줄 전송...
    2번쪠 줄 결과 수신: the man who removes a mountain begins by carrying away small stones.
    
    3번쨰 줄 전송...
    3번쪠 줄 결과 수신: change your thoughts and you change your world.
    
    4번쨰 줄 전송...
    4번쪠 줄 결과 수신: the great pleasure in life is doing what people say you cannot do.
    
    5번쨰 줄 전송...
    5번쪠 줄 결과 수신: every great achievement was once impossible.
    
    6번쨰 줄 전송...
    6번쪠 줄 결과 수신: diligence is the mother of good fortune.
    
    7번쨰 줄 전송...
    7번쪠 줄 결과 수신: the busy bee has no time for sorrow.
    
    8번쨰 줄 전송...
    8번쪠 줄 결과 수신: it takes twenty years to make an overnight success.
    
    9번쨰 줄 전송...
    9번쪠 줄 결과 수신: the laziest people have the biggest plans for tomorrow.
    
    10번쨰 줄 전송...
    10번쪠 줄 결과 수신: all things are difficult before they are easy.
    === 처리 통계 ===
    처리 모드: lower
    처리한 줄 수: 10줄
    소요 시간: 0.00초

```



### 클라이언트: reverse

```

./file_processor_clnt test.txt reverse

    1번쨰 줄 전송...
    1번쪠 줄 결과 수신: .pets elgnis a htiw snigeb selim 0001 fo yenruoj A
    
    2번쨰 줄 전송...
    2번쪠 줄 결과 수신: .senots llams yawa gniyrrac yb snigeb niatnuom a sevomer ohw nam ehT
    
    3번쨰 줄 전송...
    3번쪠 줄 결과 수신: .dlrow ruoy egnahc uoy dna sthguoht ruoy egnahC
    
    4번쨰 줄 전송...
    4번쪠 줄 결과 수신: .od tonnac uoy yas elpoep tahw gniod si efil ni erusaelp taerg ehT
    
    5번쨰 줄 전송...
    5번쪠 줄 결과 수신: .elbissopmi ecno saw tnemeveihca taerg yrevE
    
    6번쨰 줄 전송...
    6번쪠 줄 결과 수신: .enutrof doog fo rehtom eht si ecnegiliD
    
    7번쨰 줄 전송...
    7번쪠 줄 결과 수신: .worros rof emit on sah eeb ysub ehT
    
    8번쨰 줄 전송...
    8번쪠 줄 결과 수신: .sseccus thginrevo na ekam ot sraey ytnewt sekat tI
    
    9번쨰 줄 전송...
    9번쪠 줄 결과 수신: .worromot rof snalp tseggib eht evah elpoep tseizal ehT
    
    10번쨰 줄 전송...
    10번쪠 줄 결과 수신: .ysae era yeht erofeb tluciffid era sgniht llA
    === 처리 통계 ===
    처리 모드: reverse
    처리한 줄 수: 10줄
    소요 시간: 0.00초

```



### 서버

```

    1번째 줄 처리 중...
    2번째 줄 처리 중...
    3번째 줄 처리 중...
    4번째 줄 처리 중...
    5번째 줄 처리 중...
    6번째 줄 처리 중...
    7번째 줄 처리 중...
    8번째 줄 처리 중...
    9번째 줄 처리 중...
    10번째 줄 처리 중...
```