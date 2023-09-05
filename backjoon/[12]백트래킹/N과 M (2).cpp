#include <bits/stdc++.h>
using namespace std;
int arr[9] = { 0, };
int visited[9] = { 0, };
int n, m;

void func(int first, int x, int seq)
{
	if (x == 0)
	{
		for (int i = 0; i < m; i++)cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (first > i || visited[i])continue;
		visited[i] = 1; //방문체크를 하는 이유는 1,1 과 같은 중복을 없애기 위함
		arr[seq] = i;
		func(i, x - 1, seq + 1);
		visited[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(1, m, 0);
	return 0;
}
