#include <bits/stdc++.h>
using namespace std;
int board[100][100] = { 0, };
int visited[100][100] = { 0, };
queue<pair<int, int>> q;
int width[100] = { 0, };
int cnt = 0;
int area = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int m, n, k;
void bfs(int x, int y)
{
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty())
	{
		area++; //q에 들어온 횟수가 넓이 이다.
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (visited[nx][ny] || board[nx][ny]) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;
	//m : 가로
	//n : 세로
	for (int i = 0; i < k; i++)
	{
		int lx, ly, rx, ry;
		cin >> ly >> lx >> ry >> rx;
		for (int j = lx; j < rx; j++)
		{
			for (int g = ly; g < ry; g++)
			{
				board[j][g] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 1 && visited[i][j] == 0)
			{
				bfs(i, j);
				width[cnt] = area;
				area = 0;
				cnt++;
			}
		}
	}
	sort(width, width + cnt);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		cout << width[i] << " ";
	}

	return 0;
}