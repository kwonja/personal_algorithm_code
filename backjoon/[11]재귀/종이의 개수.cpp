#include <bits/stdc++.h>
using namespace std;
int arr[7000][7000] = { 0, };

int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;

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
		if (arr[r][c] == -1)cnt1++;
		if (arr[r][c] == 0)cnt2++;
		if (arr[r][c] == 1)cnt3++;
		return;
	}
	int div = n / 3;

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

	cout << cnt1 << "\n";
	cout << cnt2 << "\n";
	cout << cnt3 << "\n";


}

// 재귀형태로 분할하면서 위치를 전달해주는것이 포인트
