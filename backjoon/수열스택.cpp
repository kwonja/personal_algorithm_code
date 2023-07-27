#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> seq;
	vector<char> oper;
	vector<int> stack;
	int cnt = 0;
	int k, input;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> input;
		seq.push_back(input);
	}
	for (int i = 0; i < k; i++)
	{
		stack.push_back(i + 1);
		oper.push_back('+');

		while (!stack.empty() && (seq[cnt] == stack.back()))
		{
			stack.pop_back();
			oper.push_back('-');
			cnt++;
		}
	}
	if (!stack.empty())
	{
		cout << "NO";
	}
	else
	{
		for (auto i : oper)
			cout << i << "\n";
	}
	return 0;
}