#include <bits/stdc++.h>
using namespace std;
int arr[9] = { 0, };
int n, m;

void func(int n, int x, int seq)
{
	if (x == 0)
	{
		for (int i = 0; i < m; i++)cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[seq] = i;
		func(n, x - 1, seq + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(n, m, 0);
	return 0;
}