## 0x05강 스택 👾
#### 0x00 정의와 성질
**[스택]**
<br>한쪽 끝에서만 원소를 넣거나 뺄 수 있는 자료구조 👉 구조적으로 먼저 들어간 원소가 제일 나중에 나오게 됨(FILO, First In Last Out) <br>
* 참고로 큐나 덱도 스택처럼 특정 위치에서만 원소를 넣거나 뺄 수 있는 제한이 걸려있음. 👉 스택, 큐, 덱을 묶어 Restricted Structure라고 부름

● 성질
기능|시간복잡도
---|:---:
원소의 추가 | O(1)
원소의 제거 | O(1)
제일 상단의 원소 확인 | O(1)
*제일 상단이 아닌 나머지 원소들의 확인 / 변경이 원칙적으로 불가능 

👉 스택에서는 제일 상단이 아닌 나머지 원소들의 확인/변경 기능이 제공 X, STL stack에서도 이 기능은 X

#### 0x01 기능과 구현
- 구현 

``` C++
const int MX = 1000005;
int dat[MX];
int pos = 0;
```

: 스택은 배열 혹은 연결 리스트를 이용해서 구현 가능, 이 중에서도 배열을 이용하는게 구현이 더 쉬움
- 스택을 배열로 구현 👉 단지 원소를 담은 큰 배열 한 개와 인덱스를 저장할 변수 한 개만 필요
- pos : 다음에 원소가 추가될 때 삽입해야할 곳을 가리킴, 이 값이 곧 스택의 길이, 즉 스택 내의 원소의 수를 의미

#### 0x02 STL stack

● 스택이 비어있는데 top을 호출 👉 런타임 에러 <br>
● 스택이 비어있는데 pop을 호출 👉 런타임 에러 <br>
> **👉 조심해야함 ❗️❗️❗️❗️❗️❗️**

