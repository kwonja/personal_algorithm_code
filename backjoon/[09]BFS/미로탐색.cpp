#include <bits/stdc++.h>
using namespace std;
string board[101];
int dist[101][101] = { 0, };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	dist[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (dist[nx][ny] || board[nx][ny] == '0')continue;
			q.push({ nx,ny });
			dist[nx][ny] = dist[curx][cury] + 1; //��ĭ ����

		}
	}
	cout << dist[n - 1][m - 1];
	//�ּҰ��̶� �����ؼ� ���ܸ� ã�������ߴµ�
	//��� �����غ��� �簢���� ������鼭 �Ÿ��� ���ϸ� ������� ���Ǵ°��� �ּҰ��̴�.
	return 0;
}