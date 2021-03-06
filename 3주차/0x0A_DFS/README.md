## 0x0A강 DFS 👾

#### 0x00 알고리즘 설명
[DFS(Depth First Search) : 다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘] <br>
cf ) BFS : 깊이 대신 너비 우선

#### 0x01 예시
1. 시작하는 칸을 스택에 넣고 방문했다는 표시를 남김
2. 스택에서 원소를 꺼내어 그 칸과 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌 때까지 2번을 반복 <br>
모든 칸이 스택에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때, O(N) <br>
(BFS 과정과 다 똑같고 큐만 스택을 바뀜, BFS : 큐 / DFS : 스택)

👉 Flood Fill이 필요할 때 사용 가능 <br>
👉 BFS와 DFS 모두 최종적인 방문 결과는 똑같지만 방문 순서에서 아주 큰 차이가 있음

#### 0x02 BFS vs DFS
BFS : 큐 사용 / DFS : 스택 사용 but, 원소 하나를 빼내고 주변을 살펴본다는 알고리즘의 흐름은 똑같음 <br>
: 둘의 방문 순서는 큰 차이가 있음

시작점 : 중앙 <br>
1) BFS : 동심원처럼 상하좌우로 퍼져나감 👉 BFS 성질인 거리순으로 방문한다는 것을 보여줌

2) DFS : 이미지 👉 한 방향으로 막힐 때까지 쭉 직진 

- BFS : “현재 보는 칸으로부터 추가되는 인접한 칸은 거리가 현재 보는 칸보다 1만큼 더 떨어져 있다.” <br>
: 이 성질 ) DFS에서는 성립 X 👉 DFS로 거리 계산 불가

: 다차원 배열에서 굳이 BFS 대신 DFS를 써야하는 일이 없음. Flood Fill은 BFS와 DFS 중에서 어느 것을 상관없지만, 거리 측정은 BFS만 가능 --> BFS 대신 DFS 쓸 일 X

: DFS가 아예 쓸모없는 것은 아니고, 그래프와 트리라는 자료구조를 배울 때 DFS 필요
