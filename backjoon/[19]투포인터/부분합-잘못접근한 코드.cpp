#include <bits/stdc++.h>
using namespace std;
int arr[100001] = { 0, };
int ans = 100011;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	long long sum = 0;
	int len = 0;
	int point = 0; //0���� ����
	while (point < n)
	{
		if (point == 0)
		{
			sum += arr[point];
			len++;
			point++;
			continue;
		}
		if ((arr[point] - arr[point - 1]) == 1) //���ӵ� �����
		{
			sum += arr[point];
			len++;
			point++;
			if (sum >= s)
			{
				ans = min(ans, len);
				//�ڿ� ���ӵȴٸ�?�ʿ䰡 ����
				while (point < n)
				{
					if ((arr[point] - arr[point - 1]) == 1)point++;
					else break;
				}
				//������ ������ ���� pointer�� ���� �������ش�.
				sum = arr[point];
				len = 1;
				point++;
			}
		}
		else //���ӵ� ���� �ƴ϶��
		{
			sum = arr[point];
			len = 1;
			point++;
		}
	}
	if (ans == 100011)cout << 0 << "\n";
	else cout << ans << "\n";
	return 0;
}

//�����ϴ� ���� ���� ������ �ڵ带 �ۼ��ߴ�.
// ���ӵ� ������ �κ�����... -> ���ľ��� ������ ��..... ������ ���⼭ �κ����� ���ϰ� ���� s �̻��� �κп��Ӽ����� ���̰� ���� ª������ ������.