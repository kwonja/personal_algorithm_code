#include <bits/stdc++.h>
using namespace std;
int m, n, h;
int mx = 1;
int board[101][101][101] = { 0, };
int visited[1001][101][101] = { 0, };
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<int*> q;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> h;
	for (int g = 0; g < h; g++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> board[i][j][g];
				if (board[i][j][g] == 1)
				{
					q.push(new int[3]{ i,j,g });
					visited[i][j][g] = 1;
				}
				if (board[i][j][g] == -1)visited[i][j][g] = -1;
			}
		}
	}
	while (!q.empty())
	{
		int curx = q.front()[0];
		int cury = q.front()[1];
		int curz = q.front()[2];
		delete[] q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			int nz = curz + dz[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (board[nx][ny][nz] == -1 || visited[nx][ny][nz])continue;
			visited[nx][ny][nz] = visited[curx][cury][curz] + 1;
			q.push(new int[3]{ nx,ny,nz });
			if (visited[nx][ny][nz] > mx)mx = visited[nx][ny][nz];
		}
	}
	for (int g = 0; g < h; g++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visited[i][j][g] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << mx - 1;

	return 0;
}