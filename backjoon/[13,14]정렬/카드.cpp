#include <bits/stdc++.h>
using namespace std;
string str;

int n;
int maxindex, maxcnt, cnt;
long long arr[100001] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])cnt++;
		else cnt = 0;
		if (cnt > maxcnt)
		{
			maxindex = i;
			maxcnt = cnt;
		}
	}
	cout << arr[maxindex];
	return 0;
}