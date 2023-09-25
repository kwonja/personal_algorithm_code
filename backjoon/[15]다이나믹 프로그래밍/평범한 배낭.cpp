#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[101][100001] = { 0, };
vector<pair<int, int>> item;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		item.push_back({ w,v });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			//�賶�� �ִ빫�� ���� ������ ���԰� ������
			if (item[i - 1].first > j)
			{
				arr[i][j] = arr[i - 1][j];
				continue;
			}
			//���濡 ������ ������
			arr[i][j] = arr[i - 1][j - item[i - 1].first] + item[i - 1].second;
			//������ �ִ� ���� ���Կ� ���� �־�����, ���� ���Կ��� ������ǰ�� ��ġ�� �� ������ ����
			arr[i][j] = max(arr[i][j], arr[i - 1][j]);
		}
	}
	cout << arr[n][k];
	return 0;
}
// ���̺���
// arr[i][w] -> i�� ������ ���� w ��ŭ ���Ը� �־����� �ִ� ���ġ
// i�� ��ǰ�� �� Ƚ��, w�� ������ �ִ� ������ ����

// ��ȭ��
// �賶�� �ִ빫�Ժ��� ������ ���ſﶧ
// arr[i][w]= arr[i-1][w]

// ������ ���� ���� ���� ������ ������
// arr[i][w]= arr[i-1][w-k]+�������� ��ġ

// ���ο� �������̶� �������� �ʾ�����
//arr[i][w]= arr[i-1][w]

// w��� �ִ� �賶�� ���ؼ� ������ �������� ��ġ�� 
// i��° ���ǿ� ���� w ��� ������ �ִ� �賶���� ������ �ֱ⶧���� ��
// �׻� �ִ� �̻�ġ�� ����ذ��鼭 ���ؾ��Ѵ�.
// arr[i][w]= max(arr[i-1][w-k]+�������� ��ġ,arr[i-1][w])