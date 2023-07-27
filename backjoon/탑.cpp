#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> stack;
	vector<int> seq;
	int k, input;
	cin >> k;


	for (int i = 0; i < k; i++)
	{
		cin >> input;

		while (!stack.empty() && (stack.back().second < input))
		{
			stack.pop_back();
		}
		if (stack.empty())
		{
			seq.push_back(0);
			stack.push_back(make_pair(i + 1, input));
		}
		else
		{
			seq.push_back(stack.back().first);
			stack.push_back(make_pair(i + 1, input));
		}
	}
	for (auto i : seq)
	{
		cout << i << " ";
	}

	return 0;
}