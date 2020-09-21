## 0x03강 배열 👾 

#### 0x00 정의와 성질
1. O(1)에 k번째 원소를 확인/변경 가능
👉 메모리 상에 원소를 연속하게 배치한 자료구조 👉 k번째 원소의 위치를 바로 계산 가능

2. 추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음
3. Cache hit rate 가 높음
4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림

기능 | 시간복잡도
---|:---:|
임의의 위치에 있는 원소를 확인/변경 | O(1)
원소를 끝에 추가 | O(1)
마지막 원소를 제거 | O(1)
임의의 위치에 원소를 추가 / 임의의 위치에 원소 제거 | O(N)

#### 0x01 기능과 구현
● 사용팁
배열 전체를 효울적으로 특정 값 초기화 방법

  1. cstring 헤더에 있는 memset 함수 활용  

ex) 
``` C++
int a[21];
    memset(a, 0, sizeof a);
``` 
: 실수할 여지 多 <br> ex) 0이나 –1이 아닌 다른 값 넣으면 오작동, 2차원 이상의 배열을 함수의 인자로 넘겨 그 곳을 memset하면 잘못 들어감 👉 비추천

2. for문 : 투박하긴 하나 실수할 여지 없어 무난하고 좋음

3. algorithm 헤더의 fill 함수 이용 
실수할 여지도 별로 없고, 코드도 짧아 익숙해지면 가장 추천

#### 0x02 STL vector
- 배열과 거의 동일한 기능 수행, 배열과 마찬가지로 원소가 메모리에 연속하게 저장 👉 O(1)에 인덱스를 가지고 각 원소로 접근 가능 <br>
*BUT, 배열과 달리 크기를 자유자재로 늘이거나 줄일 수 있다는 장점*

기능 | 시간복잡도
---|:---:|
insert, erase | O(N)
push_back, pop_back : 제일 끝에 원소 추가/제거 | O(1)
push_front, pop_front : 제일 앞 원소 추가/제거 | O(N)

vector에서 =를 사용 👉 deep copy 발생 (v3 = v4; 후 v4를 바꿔도 v3에 영향x)

[vector의 모든 원소를 순회하고자 할 때]
``` C++
vector<int> v1 = {1,2,3,4,5};

// 1.range-based for loop (since C+11)
// if int e : v1 --> 복사된 값이 e에 들어감
// if int& e : v1 --> 원본이 e에 들어감
for(int e : v1)
	cout << e << “ ”;

// 2. not bad
for(int i = 0; i < v1.size();i++)
	cout << v1[i] << “ ”;

// 3. ***WRONG***
// 기본적으로 vector의 size 메소드는 unsigned int 반환 
// --> v1이 빈 vector일 때 v1.size() - 1이 unsigned int 0에서 int 1을 빼는 식이 되고, unsigned int와 int를 연산하면 unsigned int로 자동 형변환이 발생 
// --> (unsigned int)0 - (int)1은 –1이 아니라 4294967295가 됨 (4294967295 : unsigned int overflow로 인해 생긴 값)
for(int i = 0; i <= v1.size() - 1; i++)
	cout << v1[i] << “ ”;
```
**size 메소드의 반환값이 unsigned int이기 때문에 3번처럼 구현하지 말자!**
