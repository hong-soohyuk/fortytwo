# 42 CURSUS

42서울에서 진행하는 ecole42 본 과정 과제를 기록하기 위한 repository.

- [libft](#libft)
- [get_next_line](#get_next_line)
- [printf](#printf)
- [born2beroot](#born2beroot)
- [push_swap](#push_swap)

## libft

```shell
cd ./libft
make all
make bonus
```
`libc`의 일부 모듈을 직접 구현하여 라이브러리로 만드는 과제.
이후 ecole 42 과제를 진행하면서 해당 과제에서 만들어 둔 라이브러리를 사용하게 된다.

### allowed functions
1. write on <unistd.h>
2. malloc on <stdlib.h>
3. free on <stdlib.h>

- ### 1) strlen, strncmp, atoi 등 가장 빈번히 사용되는 모듈 구현

구현 도중 메모리 누수(memory leaks)에 대한 철저한 관리와 heap 메모리 부족으로 인한 malloc 실패, 입력값 에러에 대한 예외 처리 등 적절한 에러 핸들링을 통한 gracefully shutdown 지향

- ### 2) LinkedList 의 개념 이해와 구현

연속적인 배열이 아닌 heap영역에 할당된 메모리를 관리하고, 구조체와 구조체에 선언된 변수와 또 다른 메모리를 관리할 수 있도록 함.

-----

## get_next_line

fd를 통해 파일에 접근해 파일의 내용을 한 줄(`'\n'`) 단위로 나누어 반환하는 함수 작성.

함수 실행 context에서 종료된 뒤에도 반환된 내용 이후의 내용부터 정상적으로 반환해주도록 한다.

- ### fd(file descriptor)?
유닉스 내에 존재하는 모든 것은 파일이다. 흔히 떠올리는 Regular file부터, Directory, Socket, Pipe 등 모든 객체는 파일로 관리된다.
유닉스 환경에선 process가 위와 같은 파일에 접근할 때 file descriptor라는 개념을 사용하도록 한다.

- ### 1) fd table
fd table은 프로세스 단위로 할당되는 테이블이다. 프로세스 마다 각자의 fd table을 가지게 되며, fd table의 각 index는 file table을 참조 할 수 있도록 포인터를 가지게 된다.
프로세스가 활성화 되면서 기본적으로 0, 1, 2 index가 활성화되면서 각각 standard input, standard output, standard error에 대한 fd table 주소를 가지게 된다.

```c
write(1, "writing on stdout", 17); // write(int fd, const void *buf, size_t count)
```
- ### 2) static variable
static 변수는 `Data Segment`에 위치하며, 별도의 초기화가 없더라도 0으로 초기화 된다.
런타임 이전에 값이 결정되므로 함수 호출을 통해 값을 초기화 할 수 없다.

```c
char	*get_next_line(int fd)
{
	static t_fd_node	*fd_list;
	t_fd_node			*fd_node;
	char				*return_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	...
```
`get_next_line`과제는 프로그램이 아닌 함수를 작성하는 과제이다. 함수가 어떤 프로세스에서 실행 되었을때, `get_next_line`이 어떠한 값을 반환하고 종료한 뒤에도 프로그램이 종료되기 전까지 static 변수는 이전 값을 저장할 수 있다.

`Stack segment가 아닌 Data segment에 저장하는 변수이기 때문이다.`

- ### 3) LinkedList의 활용
한 프로그램 안에서 여러 fd를 동시에 열어서 파일들을 읽어들일 경우 다른 파일(fd)을 읽은 다음 다시 원래의 파일(fd)을 읽을 경우 이전까지 반환한 값 부터 다시 반환 가능해야한다.

-----

## printf

-----

## born2beroot
virtual machine에 linux를 설치하고, package manager, sudo, password policy, ufw를 학습.

- ### 1) vm?
VM은 `Hypervisor` 위에서 작동한다. 하이퍼바이저가 하드웨어의 자원을 사용하여 VM을 생성하고 구동하게 된다.
- type 1 hypervisor, `Bare-metal Architecture`, 물리적인 하드웨어 위에 여러 Guest 가 설치된다.
- type 2 hypervisor, `Hosted Architecture`, 물리적인 하드웨어 위에 여러 Guest 가 설치된다.

- what is the point of using VM?
    - 가상 환경을 하나의 infra를 사용해서 구축 할 수 있기 때문에 비용 면에서 장점이있다.
    - 실제 컴퓨터를 구입하지 않아도 새로운 운영체제를 구동할 수 있다.
    - 호스트가 예기치 않게 중단될 경우 스냅샷, 백업 대책이 마련되어있다.

- ### 2) UFM (Uncomplicated Firewall)
`netfilter Module`는 네트워크 통로를 단일화해 내부 정보망을 보호하기 위한 시스템으로, 내부망과 외부망을 분리하여 접근 제어한다.

Uncomplicated Firewall은 말 그대로 복잡하지 않고 간단한 명령어로 `netfilter Module` 을 관리하는 프레임워크이다, 과제에선 `port 22`를 닫고 `port 4242`를 여는데 사용한다.
대표적으로 외부 침입자가 내부 `network`에 침입하는 경우를 막기 위해서 `UFW`를 사용한다.

- ### 3) sudo (super do, substitute user do)
	- 침입자가 `sudo`를 사용 하면 `sudoers`에 자신이 노출되기에 침입을 확인할 수 있다는 장점이 있다.
	- `root` 계정에 장시간 머무를 일이 없어져서 위험한 `command`를 실행할 가능성이 낮아진다.
	- `sudo` 사용 시에는 `log`가 남아 추적이 쉽다. `root` 계정에서 작업하면 `log`가 남지 않는다
    	- command 단위의 로그가 남아서 무분별한 root 사용보다, 더 정확한 기록을 찾을 수 있다.
	- `root`의 `password`를 타인과 공유하지 않아도 되어, 보안에 편리하다.

- ### 4) cron
특정 작업을 특정 시간에 자동으로 실행 시키기 위한 Daemon이다. crontab 이라는 설정 파일을 기반으로 작동한다.
> Daemon: 사용자의 영역에서 벗어나 Background에서 실행되고있는 프로세스를 말한다. 어원은 맥스웰의 악마로, 눈에 보이지 않고도 알아서 할 일을 다 해준다는 의미에서 명칭을 가져왔다

추가로, sudo 권한을 편집할 수 있는 `visudo`에서 `requiretty` 을 설정하는데, cron와 같은 daemon이 함부로 sudo 명령어를 실행하지 않게 하기 위한 설정이다.

-----

## push_swap

a와 b라는 두 개의 Stack(과제는 dequeue로 구현)가 주어지며,

프로그램의 인자로 주어지는 값들을 parsing 하여 stack a에 차례대로 넣은 후,

과제에서 주어진 명령어들에 따라 스택을 조정해 최종적으로 오름차순 정렬된 stack a를 만드는 프로그램을 작성한다.

| the rules			| functionality                  |
| ----------------- |:-----------------|
| sa (swap a)		| Swap the first 2 elements at the top of stack a. |
| sb (swap b)		| Swap the first 2 elements at the top of stack b. |
| ss (swap a, b)	| sa and sb at the same time. |
| pa (push a)		| Take the first element at the top of b and put it at the top of a. |
| pb (push b)		| Take the first element at the top of b and put it at the top of b. |
| ra (rotate a)		| Shift up all elements of stack a by 1. |
| rb (rotate b)		| Shift up all elements of stack b by 1. |
| rr (rotate a, b)	| ra and rb at the same time. |
| rra (reverse a)	| Shift down all elements of stack a by 1.|
| rrb (reverse a)	|  Shift down all elements of stack b by 1. |
| rrr (reverse a, b)| rra and rrb at the same time.|
