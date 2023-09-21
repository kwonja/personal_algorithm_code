#include <bits/stdc++.h>
using namespace std;
int n;
int color[3] = { 0, };
int arr[1001][3] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> color[j];
		}
		if (i == 1)
		{
			arr[i][0] = color[0];
			arr[i][1] = color[1];
			arr[i][2] = color[2];
		}
		else
		{
			arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + color[0];
			arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + color[1];
			arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + color[2];
		}
	}
	cout << min(arr[n][0], min(arr[n][1], arr[n][2]));
	return 0;
}