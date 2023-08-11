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

*/