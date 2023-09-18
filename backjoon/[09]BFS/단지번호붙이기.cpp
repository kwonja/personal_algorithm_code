#include <bits/stdc++.h>
using namespace std;
string board[26];
int visitied[26][26] = { 0, };
queue<pair<int, int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, cnt, area;
int width[625] = { 0, };
void bfs(int x, int y)
{
	q.push({ x,y });
	visitied[x][y] = 1;

	while (!q.empty())
	{
		area++;
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (visitied[nx][ny] || board[nx][ny] == '0') continue;
			q.push({ nx,ny });
			visitied[nx][ny] = 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}