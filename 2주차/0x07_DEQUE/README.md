## 0x07강 덱 👾
#### 0x00 정의와 성질
[덱, deque = Double Ended Queue] <br>
 : Restricted Structure의 끝판왕, 양쪽 끝에서 삽입과 삭제 전부 가능 

● 성질
기능|시간복잡도
---|:---:
원소의 추가 | O(1)
원소의 제거 | O(1)
제일 앞/뒤의 원소의 확인 | O(1)
*제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

: STL deque 👉 인덱스로 원소에 접근 가능 

#### 0X01 기능과 구현
- 구현
``` C++
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;
```

: 배열 혹은 연결리스트 둘 다를 가지고 구현 가능 bu, 배열 이용한 구현이 더 쉬우므로 배열만 다룸<br>

● 큐와 다른 점 : head, tail의 초기값이 0이 아닌 MX <br>
cf) 큐 : 앞쪽은 제거, 뒤쪽은 삽입만 발생 👉 배열 내에서 실제 큐에 들어간 원소들이 차지한 공간이 점점 오른쪽으로 이동하면서 확장하는 모양

덱 : 양쪽에서 모두 삽입 가능 👉 여의봉처럼 양쪽으로 확장 <br>
(시작 지점 : 0 👉 왼쪽으로 확장 불가 / <br>
시작 지점을 배열의 중간으로 두는 것이 양쪽으로 확장 가능 👉 배열의 크기 : 2*MX + 1, head와 tail의 초기값 : MX)

#### 0x02 STL deque
- STL deque : <br>
double ended queue라는 느낌보다 vector랑 비슷한데 frontd서도 O(1)에 추가와 제거가 가능한 느낌이 강함 <br>
pop_front, push_front, pop_back, push_back 외에도 insert도 있고, erase도 있고 인덱스로 원소에 접근도 가능

: STL vector에서 제공되는 기능을 STL deque에서도 다 제공 + front에서 O(1)에 추가 및 제거 가능하니 deque가 vector의 상위호환이라는 생각할 수 O <br>
BUT, vector와 달리 deque은 모든 원소들이 메모리상에 연속하게 배치되어있지 X

So 앞,뒷쪽에서의 추가/제거 모두 필요하면 STL deque / 굳이 앞쪽에서의 추가/제거 필요 X, 배열과 같은 느낌으로 쓰고 싶을 땐 STL vector
