#include <bits/stdc++.h>
using namespace std;

int arr[100001] = { 0, };


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	int move[2] = { 1,-1 };
	cin >> n >> k;
	queue<int> q;
	fill(arr, arr + 100001, -1); //-1�� ������ �ȵȰ�
	q.push(n);
	arr[n] = 0; //ó�� ����
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == k)
		{
			cout << arr[cur];
			return 0;
		}
		for (int i = 0; i < 2; i++)
		{
			int next = cur + move[i];
			if (next < 0 || next>100000)continue; //������ ���������� ������ *2�� ��� �ϰԵɼ� �ִ�.
			if (arr[next] != -1)continue;
			q.push(next);
			arr[next] = arr[cur] + 1;
		}
		int next = cur * 2;
		if (next < 0 || next>100000)continue;
		if (arr[next] != -1)continue;
		q.push(next);
		arr[next] = arr[cur] + 1;

	}
	return 0;
}