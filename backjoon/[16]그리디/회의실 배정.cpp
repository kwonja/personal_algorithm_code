#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;
int endpoint;
vector<pair<int, int>> arr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		arr.push_back({ end,start });
	}
	//끝나는 시간을 정렬해야해서 순서를 바꿈
	sort(arr.begin(), arr.end());
	endpoint = arr[0].first;
	cnt++;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].second >= endpoint)
		{
			endpoint = arr[i].first;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}