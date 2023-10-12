#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[20001] = { 0, };
int b[20001] = { 0, };
int cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int j = 0; j < m; j++)
		{
			cin >> b[j];
		}
		sort(a, a + n);
		sort(b, b + m);
		for (int j = 0; j < n; j++)
		{
			for (int h = 0; h < m; h++)
			{
				if (a[j] <= b[h])break;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}