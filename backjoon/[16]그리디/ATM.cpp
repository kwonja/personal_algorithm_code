#include <bits/stdc++.h>
using namespace std;
int n;

int arr[1000] = { 0, };
int s[1000] = { 0, };
int sum = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	arr[0] = s[0]; //1��
	for (int i = 1; i < n; i++)
	{
		arr[i] = arr[i - 1] + s[i];
	}
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	cout << sum;
	return 0;
}
//���̺�
//�ּҰ��� ���ؾ��ϱ⶧����
//���� ���������»������ �տ��� �������Ѵ�.
//-> ���� ���� ���� �ݺ��ؾ� �ּҰ��� �ȴ�.
//arr[i] i��°���� �ɸ��� �ð�
//arr[i]=arr[i]+a[i]