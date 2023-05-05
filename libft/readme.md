## libft
📚

```shell
cd ./libft
make all
make bonus
```
`libc`의 일부 모듈을 직접 구현하여 라이브러리로 만드는 과제.
이후 ecole 42 과제를 진행하면서 과제를 통해 만들어 둔 라이브러리를 사용한다.

### allowed functions
1. write on <unistd.h>
2. malloc on <stdlib.h>
3. free on <stdlib.h>

- ### 1) strlen, strncmp, atoi 등 가장 빈번히 사용되는 모듈 구현

익숙하게 사용하는 간단한 함수마저 구현 도중 메모리 누수(memory leaks)에 대한 철저한 관리와 heap 할당 실패 (malloc의 예외 처리), 입력값 에러에 대한 예외 처리 등 적절한 에러 핸들링을 통한 gracefully shutdown 지향

- ### 2) LinkedList 의 개념 이해와 구현

연속적인 배열이 아닌 heap영역에 할당된 메모리를 관리하고, 구조체와 구조체에 선언된 변수와 또 다른 메모리를 관리할 수 있도록 함.
