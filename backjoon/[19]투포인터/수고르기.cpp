#include <bits/stdc++.h>
using namespace std;
int arr[100001] = { 0, };
int ans = 2000000001;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st, ed;
	st = ed = 0; //
	while (ed != n)
	{
		if (arr[ed] - arr[st] < m)ed++;
		else //m ���� ũ�ų� ������
		{
			ans = min(ans, arr[ed] - arr[st]);
			st++;
		}
	}
	cout << ans << "\n";
	return 0;
}

//���ϴ°��� �ּҰ��̱⿡ st, ed�� ���̰� m���� ū �������Ĵ� �ʿ����
//arr[ed]-arr[st]>=m �� �����ϸ� st�� �÷� ���̸� ���ϰ� m���� ũ�鼭 �� �������̸� �����Ѵ�.
//m���� ���̰� ������ ed�� �ڷ� �����鼭 �ִ� O(2n)�� �ð����⵵�� ������.
//������ �ݺ��ϴ°��� �ƴ� Ŀ���� �ű�鼭 ȿ�������� Ž���� �� �ִ�.