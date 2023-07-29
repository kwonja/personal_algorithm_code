#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		stack<char> stk;
		cin >> str;
		for (auto c : str)
		{
			if (stk.empty()) stk.push(c);
			else if (stk.top() != c)
			{
				stk.push(c);
			}
			else if (stk.top() == c)
			{
				stk.pop();
			}
		}
		if (stk.empty())count++;
	}
	cout << count;
}