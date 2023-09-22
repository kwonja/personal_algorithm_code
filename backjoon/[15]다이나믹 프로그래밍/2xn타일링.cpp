#include <bits/stdc++.h>
using namespace std;
int n;

int  arr[1001] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;
	}
	cout << arr[n];
	return 0;
}