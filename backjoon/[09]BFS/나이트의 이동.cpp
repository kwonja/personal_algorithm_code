#include <bits/stdc++.h>
using namespace std;

int board[301][301] = { 0, };
int visited[301][301] = { 0, }; //배열크기 다른게 틀렸습니다 라고 말할수도 있다.

int dx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[8] = { 2,-2,1,-1,2,-2,1,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int g = 0; g < t; g++)
	{
		int result = 0;
		int i;
		queue<pair<int, int>> q;
		cin >> i;

		for (int j = 0; j < i; j++)
		{
			fill(visited[j], visited[j] + i, -1);
			fill(board[j], board[j] + i, 0);
		}
		int x, y;
		cin >> x >> y;
		q.push({ x,y });
		visited[x][y] = 0;

		int fx, fy;
		cin >> fx >> fy;
		board[fx][fy] = 1;

		while (!q.empty())
		{
			int  curx = q.front().first;
			int  cury = q.front().second;
			q.pop();
			if (board[curx][cury] == 1)
			{
				result = visited[curx][cury];
				break;
			}
			for (int j = 0; j < 8; j++)
			{
				int nx = curx + dx[j];
				int ny = cury + dy[j];
				if (nx < 0 || nx >= i || ny < 0 || ny >= i)continue;
				if (visited[nx][ny] != -1)continue;
				q.push({ nx,ny });
				visited[nx][ny] = visited[curx][cury] + 1;
			}
		}
		cout << result << "\n";

	}
	return 0;
}