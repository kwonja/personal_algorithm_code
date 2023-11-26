#include <bits/stdc++.h>
using namespace std;
int arr[100001] = { 0, };
int ans = 100001;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int st, ed;
	st = ed = 0;
	long long sum = 0;
	while (ed < n)
	{
		sum += arr[ed];
		while (sum >= s)
		{
			ans = min(ans, ed - st + 1);
			sum -= arr[st];
			st++;
		}
		ed++;
	}
	if (ans == 100001) cout << 0 << "\n";
	else cout << ans << "\n";
	return 0;
}

//st,ed를 옮기고 sum값을 저장해놓고 비교하여 시간복잡도를 줄인다.