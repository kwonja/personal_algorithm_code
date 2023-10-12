#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<pair<int, int>> arr;
int check = 0;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		check = 0;
		if (arr.empty())
		{
			arr.push_back({ input,1 });
			continue;
		}
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j].first == input)
			{
				arr[j].second++;
				check = 1;
				break;
			}
		}
		if (!check) arr.push_back({ input,1 });

	}
	stable_sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].second; j++)
		{
			cout << arr[i].first << " ";
		}
	}
	return 0;
}

// stable_sort를 사용하지않으면 동일한 우선순위에 대해서 순서를 보장해주지 않을수 있다.

