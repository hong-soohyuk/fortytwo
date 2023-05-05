## push_swap
🥞🥞

### 과제의 요구사항

두 개의 Stack을 구현하여 (dequeue),

프로그램의 인자로 주어지는 값들을 parsing 하여 stack a에 차례대로 넣은 후,

과제에서 주어진 명령어들에 따라 데이터를 두 스택에 옮길 수 있으며, 최종적으로 오름차순 정렬된 stack a를 만드는 프로그램을 작성한다.

### official commands that are used to manipulate the stacks.

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
