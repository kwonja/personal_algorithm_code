#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[500][500] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int input;
	for (int i = 0; i < n; i++) //depth
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[j][i];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				arr[j][i] = arr[j][i - 1] + arr[j][i];
			}
			else
			{
				arr[j][i] = max(arr[j - 1][i - 1] + arr[j][i], arr[j][i - 1] + arr[j][i]);
			}
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		mx = max(mx, arr[i][n - 1]);
	}
	cout << mx;
	return 0;
}