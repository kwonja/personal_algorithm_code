#include <bits/stdc++.h>
using namespace std;

int a[500001] = { 0, };
int b[500001] = { 0, };
int n, m;
int lower_idx(int target)
{
	int st = 0;
	int en = n; //왜 n이나면 target이 가장 큰수면 맨끝에 삽입해야하기때문에
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (a[mid] >= target)en = mid;
		else st = mid + 1;
	}
	return st;
}
int upper_idx(int target)
{
	int st = 0;
	int en = n; //왜 n이나면 target이 가장 큰수면 맨끝에 삽입해야하기때문에
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (a[mid] > target)en = mid;
		else st = mid + 1;
	}
	return st;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		cout << upper_idx(b[i]) - lower_idx(b[i]) << " ";
	}
	return 0;
}
