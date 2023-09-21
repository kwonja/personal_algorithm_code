#include <bits/stdc++.h>
using namespace std;
int n;
int s[301] = { 0, };
int arr[301][2] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	arr[1][1] = s[1];
	arr[1][2] = 0;
	arr[2][1] = s[2];
	arr[2][2] = s[1] + s[2];
	for (int i = 3; i <= n; i++)
	{
		arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + s[i];
		arr[i][2] = arr[i - 1][1] + s[i];
	}
	cout << max(arr[n][1], arr[n][2]);
	return 0;
}