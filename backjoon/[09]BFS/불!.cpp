#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int persondist[1002][1002] = { 0, }; //�Ÿ��� �湮Ƚ��ó������ϸ� ���� �����ϰ� �ڵ��� �� �ִ�.
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
	//��
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
			if (board[nx][ny] == '#' || firedist[nx][ny]) continue; //# �̰ų� �Ÿ��� �����Ȱ��̸� ���� �ʴ´�.
			fire.push({ nx,ny });
			firedist[nx][ny] = firedist[firex][firey] + 1;
		}
	}
	//���
	while (!person.empty())
	{
		int personx = person.front().first;
		int persony = person.front().second;
		person.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = personx + dx[i];
			int ny = persony + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) //Ż�⼺��
			{
				cout << persondist[personx][persony];
				return 0;
			}
			if (board[nx][ny] == '#' || persondist[nx][ny]) continue;
			if (firedist[nx][ny] && persondist[personx][persony] + 1 >= firedist[nx][ny])continue;
			//�ұ��� �ȹ������� 0���� �����ߴµ�, �̰� 0��ó�� ���ɼ� �ֱ⶧���� �ұ��� �������ڿ� ���� �񱳸��� �����ؾ��ϴ� ����ó���� �ؾ��Ѵ�.
			//�ұ��� �������߿��� �����ð����� �װ��� ���ų� �ʰ� ������ ��� ����
			person.push({ nx,ny });
			persondist[nx][ny] = persondist[personx][persony] + 1;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}