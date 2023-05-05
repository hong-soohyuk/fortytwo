## get_next_line
📖

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
