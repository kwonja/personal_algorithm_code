#include <bits/stdc++.h>
using namespace std;

int board[51][51] = { 0, };
int visited[51][51] = { 0, };
//방문을 한 노드를 1이라고 하자
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int t, m, n;
int k, x, y;


void bfs(int x, int y, queue<pair<int, int>> &q)
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
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] != 0 || board[nx][ny] != 1)continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	for (int g = 0; g < t; g++)
	{
		cin >> m >> n >> k;
		queue<pair<int, int>> q;
		int count = 0;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			board[y][x] = 1; //배추가 존재
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && visited[i][j] == 0)
				{
					count++;
					bfs(i, j, q);
				}
			}
		}
		//이런식으로  algorithm 헤더를 통한 fill함수로 초기화할수 있다
		//이중포문으로해도 무관하지만 조금더 깔끔한 코드를 볼 수 있다.
		for (int i = 0; i < 51; i++)
		{
			fill(board[i], board[i] + 51, 0);
			fill(visited[i], visited[i] + 51, 0);
		}
		cout << count << "\n";
	}

	return 0;
}