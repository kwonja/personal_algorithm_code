#include <bits/stdc++.h>
using namespace std;

int col[30] = { 0, };
int leftdiagonal[30] = { 0, };
int rightdiagonal[30] = { 0, };
int n;
int cnt = 0;

void func(int cur) //cur은 row를 나타냄
{
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (col[i] || leftdiagonal[i + cur] || rightdiagonal[n - 1 + i - cur]) continue; //들어갈수 없다

		col[i] = 1;
		leftdiagonal[i + cur] = 1;
		rightdiagonal[n - 1 + i - cur] = 1;
		func(cur + 1);
		col[i] = 0;
		leftdiagonal[i + cur] = 0;
		rightdiagonal[n - 1 + i - cur] = 0;
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt;

	return 0;
}

//대각선을 배열로 나타내는것이 포인트
// 또한 N개되어야한다는저