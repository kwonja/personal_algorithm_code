#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8] = { 0, };
int store[8] = { 0, };
int visited[8] = { 0, };
void func(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << store[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i])continue;
		store[cnt] = arr[i];
		visited[i] = 1;
		func(cnt + 1);
		visited[i] =s 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);

	return 0;
}