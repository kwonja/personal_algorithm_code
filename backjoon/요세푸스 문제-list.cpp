#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<int> arr;
	int n, k;
	int count = 1;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}
	auto cursor = arr.begin();
	cout << "<";
	while (!arr.empty())
	{
		if (cursor == arr.end())cursor = arr.begin();
		if (arr.size() == 1)
		{
			cout << *cursor;
			break;
		}
		if (count == k)
		{
			cout << *cursor << ", ";
			cursor = arr.erase(cursor);
			count = 1;
			continue;
		}
		count++;
		cursor++;
	}
	cout << ">";
	return 0;
}