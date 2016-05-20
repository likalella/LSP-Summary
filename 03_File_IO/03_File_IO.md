# 03 File I/O

## 1. open()
```c
#include <fcntl.h>
int open(const char *pathname, int oflag, .../* mode_t mode*/);
// 성공 시 파일 디스크립터, 오류시 -1
```

## 2. creat()
```c
#include <fcntl.h>
int creat(const char *pathname, mode_t mode);
// 성공시 쓰기전용으로 열린 파일 디스크립터, 오류 시 -1
```
open(pathname, O_RDWR | O_CREAT | O_TRUNC, mode);

## 3. close()
```c
#include <unistd.h>
int close(int filedes);
// 성공시 0, 오류시 -1
```
filedes만 지움.

## 4. lseek()
```c
#include <unistd.h>
off_t lseek(int filedes, off_t offset, int whence);
// 성공시 새 파일 오프셋, 오류시 -1
```
실제 입출력은 안 일어나고, offset만 바뀜.
파이프 지원 안됨.
특수파일에 사용 못함. (regular file만 사용가능.)
read전용으로 파일을 open한 경우, 파일크기를 넘어가지 않는다.
write전용으로 파일을 open한 경우, 파일크기를 넘어가면 Null로 채운다.(환경에 따라서 error가 나거나, garbage값으로 채우는 경우도 있다.)

## 5. read()
```c
#include <unistd.h>
ssize_f read(int filedes, void *buf, size_t nbytes);
// 읽은 바이트수, 파일끝인 경우 0, 오류시 -1
```
* 실제로 읽은 바이트수가 호출시 요청한 바이트수보다 작은 경우
(1) 정규 파일을 읽을 때, 요청된 수만큼의 바이트들을 읽기 전에 파일의 끝에 도달.
(2) 터미널 파일에서 자료를 읽을 때
(3) 네트워크에서 자료를 읽을 때
(4) 파이프나 FIFO에서 자료를 읽을 때
(5) 레코드 기반 장치에서 자료를 읽을 때
(6) 요청된 크기의 자료 중 일부만을 읽은 상황에서 시그널에 의해 연산이 가로채였을 때

## 6. write()
```
#include <unistd.h>
ssize_t write(int filedes, const void *buf, size_t nbytes);
// 성공시 기록된 바이트수, 오류시 -1
```
정규 파일의 경우 기록은 파일의 현재 오프셋에서 시작됨
쓰기를 성공적으로 완료했다면 함수는 파일 오프셋을 실제로 기록된 바이트 수만큼 증가

## 7. pread(), pwrite()
```c
```

## 8. dup(), dup2()
```c
```

## 9. sync(), fsync(), fdatasync()
```c
```

## 10. fcntl()
```c
```

## 11. iocntl()
```c
```
