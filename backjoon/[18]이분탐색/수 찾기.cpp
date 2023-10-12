#include <bits/stdc++.h>
using namespace std;
int a[100001] = { 0, };
int b[100001] = { 0, };
int n, m;

int binarysearch(int st, int ed, int target)
{
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		if (a[mid] > target)
		{
			ed = mid - 1;
		}
		else if (a[mid] == target)
		{
			return 1;
		}
		else st = mid + 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < m; i++) cout << binarysearch(0, n - 1, b[i]) << "\n";

	return 0;
}

//이분탐색을 진행할때는 n*m이 너무 큰 숫자여서 시간초과가 발생할때
// 탐색전에 정렬이 되있어야한다 -> mid를 기준으로 오른쪽이 크다는 가정이 있어야 함
