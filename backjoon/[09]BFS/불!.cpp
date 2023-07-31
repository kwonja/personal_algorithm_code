#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int persondist[1002][1002] = { 0, }; //거리를 방문횟수처럼사용하면 좀더 간결하게 코딩할 수 있다.
int firedist[1002][1002] = { 0, };



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	queue<pair<int, int>> person;
	queue<pair<int, int>> fire;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'J')
			{
				person.push({ i,j });
				persondist[i][j] = 1;
			}
			if (board[i][j] == 'F')
			{
				fire.push({ i,j });
				firedist[i][j] = 1;
			}
		}
	}
	//불
	while (!fire.empty())
	{
		int firex = fire.front().first;
		int firey = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = firex + dx[i];
			int ny = firey + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
			if (board[nx][ny] == '#' || firedist[nx][ny]) continue; //# 이거나 거리가 측정된곳이면 가지 않는다.
			fire.push({ nx,ny });
			firedist[nx][ny] = firedist[firex][firey] + 1;
		}
	}
	//사람
	while (!person.empty())
	{
		int personx = person.front().first;
		int persony = person.front().second;
		person.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = personx + dx[i];
			int ny = persony + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) //탈출성공
			{
				cout << persondist[personx][persony];
				return 0;
			}
			if (board[nx][ny] == '#' || persondist[nx][ny]) continue;
			if (firedist[nx][ny] && persondist[personx][persony] + 1 >= firedist[nx][ny])continue;
			//불길이 안번진곳을 0으로 설정했는데, 이게 0초처럼 계산될수 있기때문에 불길이 번진숫자에 대한 비교만을 진행해야하는 예외처리를 해야한다.
			//불길이 번진곳중에서 번진시간보다 그곳에 같거나 늦게 도착한 경우 제외
			person.push({ nx,ny });
			persondist[nx][ny] = persondist[personx][persony] + 1;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}