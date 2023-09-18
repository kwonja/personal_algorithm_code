#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8] = { 0, };

void func(int cnt, int cur)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[cnt] = i;
		if (i < cur) continue;
		func(cnt + 1, i);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0, 0);

	return 0;
}