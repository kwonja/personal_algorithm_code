#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000] = { 0, };
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
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i] * (n - i))max = arr[i] * (n - i);
	}
	cout << max;
	return 0;
}