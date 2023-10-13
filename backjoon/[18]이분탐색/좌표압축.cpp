#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = { 0, };
vector<int> c_arr;
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		c_arr.push_back(arr[i]);
	}
	sort(c_arr.begin(), c_arr.end());
	c_arr.erase(unique(c_arr.begin(), c_arr.end()), c_arr.end());
	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(c_arr.begin(), c_arr.end(), arr[i]) - c_arr.begin() << " ";
	}
	return 0;
}
