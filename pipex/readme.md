# 🚽 pipex

## what is the point of pipex?
```bash
export ARG="10 39 1 4 2345 14 256 64 2383 22 94"
./push_swap $ARG | ./checker $ARG
```
### push swap 프로그램의 역할
단독 수행시 sa, rra 등 제공된 자료구조(dequeue)의 데이터를 조작하기 위한 커맨드들을 결과물로 출력한다.

### checker 프로그램의 역할
단독 수행시 arguments로 전달된 숫자들을 문제의 자료구조에 저장하고, push_swap 과제에서 정의된 커맨드(sa, pb, rra 등)를 입력받기를 기다리게된다.

위의 쉘 커맨드를 실행하게되면, checker는 사용자 입력을 기다리지 않고, push_swap이 출력하는 결과를 입력받은 뒤, 정렬을 완성했는지 여부 OK 또는 KO를 출력하게 된다.

**두 개의 다른 프로세스가 통신하는 과정이 궁금하다.**

## what is envp

- `argv` stands for ***arg**ument **v**ector*
- `argc` stands for ***arg**ument **c**ount*, and
- `envp` stands for ***env**ironment **p**ointer*.

시스템 환경 변수를 담은 문자열 배열이다.

사용하는 목적은 **프로세스가 실행될 때 받은 최초의 환경변수를 개발자가 확인할 수 있게 하기 위함이다.**

```c
int	main(int argc, char *argv[], char *envp[])
{
	for (int i = 0; envp[i]; i++)
		printf("%s \n", envp[i]);
	return (0);
}
```

### 위 코드 실행시 나오는 것은
![envp.png](envp.png)

환경변수를 다룰 수 있는 함수들도 존재한다.
```c
#include <stdlib.h>

int  putenv(const char *value);
char *getenv(const char *name);
int setenv(const char *key, const char *value, int rewrite);
```

예를 들어,
```c
putenv("USER=fake_soohong");
```

위 명령어는
![putenv.png](putenv.png)

사진과 같은 결과를 보여주게 되고, 프로세스 안에서 추가되거나 변경된  환경변수는 프로세스 안에서만 유효하고, 실제 시스템 변수는 변경되지 않는다.

## List of exit codes on Linux

| Exit Code | Description |
| --- | --- |
| 0 | Successful exit without errors |
| 1 | One or more generic errors encountered upon exit |
| 2 | Incorrect usage, such as invalid options or missing arguments |
| 126 | Command found but is not executable |
| 127 | Command not found, usually the result of a missing directory in $PATH variable |
| 128 + N | Command encountered fatal error(was forcefully terminated manually or from an outside source). The N tells us which signal was received (see example below) |
| 130 (Example) | Command terminated with signal 2 (SIGINT) (ctrl+c on keyboard). 128+2 |
| 143 (Example) | Command terminated with signal 15 (SIGTERM) (kill command). 128+15 |


## dup, dup2
```c
#include <unistd.h>

int dup(int fileds);
int dup2(int fildes, int fildes2);
```
dup, dup2는 비슷한 이름을 가졌지만 역할은 많이 다르다.

### **int dup(int fileds);**
dup은 파일 식별자를 복제하는데 사용한다.
새로운 file descripter를 반환하지만, int값만 다를 뿐 원래의 파일 서술자와 같은 파일을 가리킨다.

복사 실패할 경우 -1을 반환한다. ex) 전달된 값이 fd가 아닌 경우, 더 이상 fd를 할당하지 못하는 경우.

### **int dup2(int fildes, int fildes2);**
dup2은 사용 용도가 전혀 다르다.

```c
dup2(output_file_fd, STDOUT_FILENO); → 표준 출력에 입력할 내용을 output_file_fd로 다 보내버린다.
```

## wait, waitpid

```c
#include <sys/wait.h>

pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);
```

부모 프로세스에서 fork를 통해 생성한 자식이 여러 개라면, wait함수를 이용했을때 부모 프로세스는 임의의 자식의 종료를 기다렸다가 수거하게 된다.

특정 pid를 가진 자식프로세스에 대한 wait이 불가함.

따라서 특정 프로세스에 대해서 수행할 수 있도록하는 waitpid는 pid라는 인자를 받아서 해당 프로세스를 대기할 수 있다.

### **pid_t waitpid(pid_t pid, int *statloc , int options);**

자식 프로세스의 종료를 기다리는 시스템 콜이다.

- pid

기다리고자 하는 자식 프로세스의 프로세스 아이디(pid)

- statloc

자식 프로세스가 종료 되었을때, 종료 코드를 저장할 정수형 포인터.

- options

| WUNTRACED | 자식 프로세스가 멈춘 상태에서도 pid가 반환된다. |
| --- | --- |
| WCONTINUED | 멈춘 자식 프로세스가 다시 시작되는 경우에 |
| WNOHANG | 아직 종료되지 않더라고 부모 프로세스는 계속 실행한다. 자식 중 아무것도 종료되지 않았다면 즉시 리턴. |
| WEXITED | 자식 프로세스가 종료되었을때 |
| WSTOPPED | 언트레이스와 유사, 멈춘 자식만을 대상으로 한다. |
| WNOWAIT |  |

option의 경우 각 값들을 비트 단위로 값이 지정되어있기 때문에, OR 비트연산을 통해 한번에 여러개를 지정해 사용할 수 있다.

### **pid_t wait(int *statloc);**

wait() 함수 동작 방식

1. 자식 프로세스가 동작 중이면 호출 차단이 차단되기 때문에 상태를 얻어올 때까지 대기
2. wait() 함수 호출자가 시그널을 받을 때까지 대기
3. 자식 프로세스가 종료된 상태라면 즉시 호출이 반환되어 상태를 얻음, 이 때 wait() 함수는 자식 프로세스의 프로세스 ID를 반환
4. **자식 프로세스가 없다면 호출이 즉시 반환되며, 에러값을 반환**

## int execve(const char *filename, char *const argv[], char *const envp[]);

실행가능한 파일인 filename을 현재 프로세스에 적재해 기존 실행코드와 교체한다.

현재 프로그램의 기능은 없어지고 filename 프로그램을 메모리에 올려 실행한다.

## int access(const char *pathname, int mode)

pathname으로 지정된 파일에 대해 읽기, 쓰기, 실행권한을 가지는지 체크한다.

mode R_OK(읽기), W_OK(쓰기), X_OK(실행), F_OK(파일 존재여부)

## pipe
