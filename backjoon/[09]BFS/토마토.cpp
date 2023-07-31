#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
int dist[1001][1001] = { 0, }; //거리를 방문횟수처럼사용하면 좀더 간결하게 코딩할 수 있다.
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	queue<pair<int, int>> q; //q를 떠올리는 이유를 생각해보는것도 좋겠다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
				dist[i][j] = 1;
			}
			if (board[i][j] == -1)dist[i][j] = -1; //-1인곳은 거리역시 측정하지못한다
		}
	}
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
			if (board[nx][ny] != 0 || dist[nx][ny]) continue;
			q.push({ nx,ny });
			dist[nx][ny] = dist[curx][cury] + 1;
		}
	}
	int mx = 1;
	bool error = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] > mx)mx = dist[i][j];
			if (dist[i][j] == 0) //모두익지 못하는 상황
			{
				error = true;
			}

		}
	}
	if (error)cout << -1;
	else cout << mx - 1;
	return 0;
}