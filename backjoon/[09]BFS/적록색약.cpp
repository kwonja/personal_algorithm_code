#include <bits/stdc++.h>
using namespace std;

string board[100];
int visited[100][100] = { 0, };
int n;
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int x, int y, char color)
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
			if (visited[nx][ny] != 0 || board[nx][ny] != color) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}
void colorbfs(int x, int y)
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
			if (visited[nx][ny] != 0 || board[nx][ny] == 'B') continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				count++;
				bfs(i, j, board[i][j]);
			}
		}
	}
	cout << count << " ";
	for (int i = 0; i < n; i++)
	{
		fill(visited[i], visited[i] + n, 0);
	}
	int count2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0 && board[i][j] == 'B') //B일때
			{
				count2++;
				bfs(i, j, board[i][j]);
			}
			else if (visited[i][j] == 0) //방문 안한 G나 R일때
			{
				count2++;
				colorbfs(i, j);
			}
		}
	}
	cout << count2;


	return 0;
}