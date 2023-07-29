#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count = 0;
	stack<char> stk;
	string str;
	cin >> str;
	bool error = false;
	int c = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			c = c * 2;
			stk.push(str[i]);
		}
		else if (str[i] == '[')
		{
			c = c * 3;
			stk.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (!stk.empty())
			{
				if ((i != 0) && (str[i - 1] == ')' || str[i - 1] == ']') && stk.top() == '(')
				{
					c = c / 2;
				}
				else if (stk.top() == '(')
				{
					count += c;
					c = c / 2;
				}
				else
				{
					error = true;
					break;
				}
			}
			else
			{
				error = true;
				break;
			}
			stk.pop();
		}
		else if (str[i] == ']')
		{
			if (!stk.empty())
			{
				if ((i != 0) && (str[i - 1] == ')' || str[i - 1] == ']') && stk.top() == '[')
				{
					c = c / 3;
				}
				else if (stk.top() == '[')
				{
					count += c;
					c = c / 3;
				}
				else
				{
					error = true;
					break;
				}
			}
			else
			{
				error = true;
				break;
			}
			stk.pop();
		}
		else error = true;
	}
	if (!stk.empty()) error = true;

	if (error) cout << 0;
	else cout << count;
	return 0;
}