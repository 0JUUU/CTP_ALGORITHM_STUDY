#### 0x09강 BFS 👾


STL과 함수 인자

```C++
void func(int arr[]) {
	arr[0] = 10;
}

int main(void) {
	int arr[3] = {1, 2, 3};
	func(arr);
	cout << arr[0];
}
```
👉 func에 int 배열 arr를 인자로 주는게 arr의 주소를 넘기는 것  
👉 
