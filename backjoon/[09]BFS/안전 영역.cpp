#include <bits/stdc++.h>
using namespace std;
int board[100][100] = { 0, };
int visited[100][100] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int mx, cnt;
int n;
queue<pair<int, int>> q;
void bfs(int x, int y, int height)
{
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (board[nx][ny] <= height || visited[nx][ny])continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int h = 1; h < 101; h++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && board[i][j] > h)
				{
					bfs(i, j, h);
					cnt++;
				}
			}
		}
		if (mx < cnt)mx = cnt;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = 0;
			}
		}
	}
	if (mx == 0)cout << "1"; //아무 지역도 잠기지 않았을때를 처리해줘야한다.
	else cout << mx;

	return 0;
}