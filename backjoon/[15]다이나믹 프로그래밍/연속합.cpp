#include <bits/stdc++.h>
using namespace std;
long long arr[100001] = { 0, };
long long p[100001] = { 0, };
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	arr[0] = p[0];
	for (int i = 1; i < n; i++)
	{
		arr[i] = max(arr[i - 1] + p[i], p[i]);
	}
	cout << *max_element(arr, arr + n);
	return 0;
}

// ���̺� ����
// i��° �����̰ų� ���� �����ϰų�

// ��ȭ��
// arr[i] = max (arr[i-1]+p[i],p[i])

// �ʱⰪ
// arr[0]=10