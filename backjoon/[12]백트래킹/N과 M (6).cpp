#include <bits/stdc++.h>
using namespace std;
int m, n;
int visitied[8] = { 0, };
int arr[8] = { 0, };
int store[8] = { 0, };

void func(int cnt, int num)
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
		if (i < num || visitied[i])continue; //오름차순으로 정렬했기때문에 
		store[cnt] = arr[i];
		visitied[i] = 1;
		func(cnt + 1, i);
		visitied[i] = 0;
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
	func(0, 0);
	return 0;
}