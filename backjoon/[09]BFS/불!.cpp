#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int dist[1002][1002] = { 0, }; //�Ÿ��� �湮Ƚ��ó������ϸ� ���� �����ϰ� �ڵ��� �� �ִ�.
//0 �����Ǵ±�
//-1 �ұ��� ������



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	int count = 0;
	cin >> r >> c;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	queue<pair<int, int>> person;
	queue<pair<int, int>> fire;

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'J')person.push({ i,j });
			if (board[i][j] == 'F')
			{
				fire.push({ i,j });
				dist[i][j] = -1;
			}
		}
	}
	bool esp = false;
	while (!person.empty())
	{
		int firex = fire.front().first;
		int firey = fire.front().second;
		fire.pop();

		//���
		int personx = person.front().first;
		int persony = person.front().second;
		person.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = personx + dx[i];
			int ny = personx + dy[i];
			if (board[nx][ny] == '#' || dist[nx][ny] == -1) continue;
			if (nx < 0 || nx >= c || ny < 0 || ny >= r) //Ż�⼺��
			{
				count = dist[personx][persony];
				esp = true;
				break;
			}
			person.push({ nx,ny });
			cout << nx << " " << ny << "\n";
		}
		if (esp)break;
		//�ұ�
		for (int i = 0; i < 4; i++)
		{
			int nx = firex + dx[i];
			int ny = firey + dy[i];
			if (nx < 0 || nx >= c || ny < 0 || ny >= r)continue;
			if (board[nx][ny] == '#' || dist[nx][ny] == -1) continue;
			fire.push({ nx,ny });
			dist[nx][ny] = -1;
		}
	}
	if (esp)
	{
		cout << count + 1;
	}
	else cout << "IMPOSSIBLE";

	return 0;
}