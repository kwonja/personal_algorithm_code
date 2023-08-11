#include <bits/stdc++.h>
using namespace std;
int arr[200][200] = { 0, };

int blue = 0;
int white = 0;

bool checkpaper(int n, int r, int c)
{
	int check = arr[r][c];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check != arr[r + i][c + j])
			{
				return false;
			}
		}
	}
	return true;
}
void dividepaper(int n, int r, int c)
{
	if (checkpaper(n, r, c))
	{
		if (arr[r][c] == 1)blue++;
		if (arr[r][c] == 0)white++;
		return;
	}
	int div = n / 2;

	for (int i = 0; i < n; i = i + div)
	{
		for (int j = 0; j < n; j = j + div)
		{
			dividepaper(div, r + i, c + j);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dividepaper(n, 0, 0);
	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}

/*
종이의 개수 문제와 유사하다

함수형태 fucn(int n, int 행, int 열)

base condition n=1일때인데 같은색인것을 확인하는과정에서 포함하고 있음

1. 같은색으로 칠해져 있는지 확인한다.
2. 같은색이 아니라면 n/2 * n/2 개수로 분할한다
*/