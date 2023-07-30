#include <bits/stdc++.h>
using namespace std;
int board[501][501] = { 0, };
int visited[501][501] = { 0, };
//visual studio에서 일정크기이상 넘어가는 배열을 main함수 안에 넣으면 스택오버플러우가 발생한다.
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int num = 0;
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || visited[i][j] == 1)continue;
			num++; //사진개수
			queue < pair<int, int>> q; //탐색시작
			int area = 0;
			visited[i][j] = 1; //자주빼먹는다고 말했는데도 빼먹음 ㄹㅈㄷ
			q.push({ i,j });
			while (!q.empty())
			{
				area++;
				int curx = q.front().first;
				int cury = q.front().second;
				q.pop();
				for (int g = 0; g < 4; g++)
				{
					int nx = curx + dx[g];
					int ny = cury + dy[g];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
					if (board[nx][ny] == 0 || visited[nx][ny] == 1)continue;
					q.push({ nx,ny });
					visited[nx][ny] = 1;
				}
			}
			if (mx < area) mx = area;

		}
	}
	cout << num << "\n" << mx;
	return 0;
}