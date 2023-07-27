#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> arr;
	int count = 1;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		arr.push(i + 1);
	}
	cout << "<";
	while (!arr.empty())
	{
		if (arr.size() == 1)
		{
			cout << arr.front() << ">";
			break;
		}
		if (count == k)
		{
			cout << arr.front() << ", ";
			arr.pop();
			count = 1;
			continue;
		}
		arr.push(arr.front());
		arr.pop();
		count++;
	}
	return 0;
}