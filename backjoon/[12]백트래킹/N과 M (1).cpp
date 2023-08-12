#include <bits/stdc++.h>
using namespace std;
int visited[9] = { 0, };
int arr[9] = { 0, }; //0은 안들어있는것
int n, m;
void func1(int n, int x, int seq)
{
	if (x == 0)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 1)continue;
		visited[i] = 1; //방문
		arr[seq] = i;
		func1(n, x - 1, seq + 1);
		visited[i] = 0; //다 돌아오고 나면 방문을 해제해줌
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func1(n, m, 0);
	return 0;
}

/*
배열에 숫자를 넣어놓고 출력한다는 생각을 하지 못했음
*/
