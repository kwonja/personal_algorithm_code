#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000001] = { 0, };
int pre[1000001] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	arr[1] = 0;
	arr[2] = 1;

	pre[1] = 0; //1�� pre�� �����ϱ� 0�ε����� ����Ŵ -> 0�� �������� ���ٴ��ǹ�
	pre[2] = 1;//2�� pre�� 1�̶� 1�ε����� ����Ŵ

	for (int i = 3; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0)
		{
			if (arr[i / 2] + 1 < arr[i])
			{
				arr[i] = arr[i / 2] + 1;
				pre[i] = i / 2;
			}
		}
		if (i % 3 == 0)
		{
			if (arr[i / 3] + 1 < arr[i])
			{
				arr[i] = arr[i / 3] + 1;
				pre[i] = i / 3;
			}
		}
	}
	cout << arr[n] << "\n";
	cout << n << " ";
	while (pre[n] != 0)
	{
		cout << pre[n] << " ";
		n = pre[n];
	}
	return 0;
}