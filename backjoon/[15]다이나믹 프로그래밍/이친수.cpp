#include <bits/stdc++.h>
using namespace std;
int n;
long long  arr[91][2] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	arr[1][1] = 1;
	arr[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}
	cout << arr[n][0] + arr[n][1];
	return 0;
}

//���̺� ����
//arr[i][j] ���� j�϶� ��ģ�� ����

//��ȭ��
// arr[i][0] i��° ��ģ���ε� 0���� ����
// arr[i][1] i��° ��ģ���ε� 1���� ����

// arr[i][0] = arr[i-1][0]+arr[i-1][1]
// arr[i][1] = arr[i-1][0]

//�ʱⰪ
// arr[1][1]=1;
// arr[1][0]=0;

//���� dp���� n�� Ŀ���ԵǸ�
//int�� �Ѵ°�찡 ����.