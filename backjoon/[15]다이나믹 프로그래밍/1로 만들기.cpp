#include <bits/stdc++.h>
using namespace std;
int arr[1000001] = { 0, };
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	arr[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1; //1�� ���ϴ� ���
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1); //2�� ���ϴ°��
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1); //3�� ���ϴ� ���
	}
	cout << arr[n];
	return 0;
}