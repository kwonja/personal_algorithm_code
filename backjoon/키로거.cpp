#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string tc;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tc;
		list<char> arr;
		auto cursor = arr.end();
		for (auto c : tc)
		{
			if (c == '<')
			{
				if (cursor != arr.begin())
					cursor--;
			}
			else if (c == '>')
			{
				if (cursor != arr.end())
					cursor++;
			}
			else if (c == '-')
			{
				if (cursor != arr.begin())
				{
					cursor--;
					if ((*cursor != '<') && (*cursor != '>'))
					{
						cursor = arr.erase(cursor);
					}
				}
			}
			else
			{
				arr.insert(cursor, c);
			}
		}
		for (auto &it : arr)
			cout << it;
		cout << "\n";

	}

}