#include <bits/stdc++.h>
using namespace std;
int n;
int item[1000] = { 0, };
int arr[1001] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (item[i] > item[j]) arr[i] = max(arr[i], arr[j] + item[i]);
		}
		//item[i]�� �κм����� �����϶�
		if (arr[i] == 0) arr[i] = item[i];
	}
	cout << *max_element(arr, arr + n);
	return 0;
}


// ���̺� ����
// arr[i] i��° ��ǰ�� ���� �ִ� �κ� ������ ��

//��ȭ��
//arr[i]= if(i=0;i<=i-1) ���� �������� Ȯ���ϸ鼭
//i=0 ����item[i-1] ���ӵ� ���� �ִ븦 ����

//���� ���� �ش� �������� �κм����� ���۶� arr[i]=item[i]

//�����ϴ� �κм����̶�� �̸��� �����ؾ��ߴ�...�Ф�