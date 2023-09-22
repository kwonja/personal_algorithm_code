#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100001] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (i == 1) continue;
		arr[i] += arr[i - 1];
	}
	int k, g;
	for (int i = 0; i < m; i++)
	{
		cin >> k >> g;
		cout << arr[g] - arr[k - 1] << "\n";
	}
	return 0;
}