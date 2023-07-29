#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		string str;
		stack<char> stk;
		getline(cin, str); //������ ������� ���� ���ڿ��� �޾Ƶ���
		bool balance = true;
		if (str == ".")break;
		for (auto i : str)
		{
			if ((i == '[') || (i == '('))
			{
				stk.push(i);
			}
			else if (i == ']')
			{
				if (!stk.empty() && (stk.top() == '['))
				{
					stk.pop();
				}
				else
				{
					balance = false;
				}
			}
			else if (i == ')')
			{
				if (!stk.empty() && (stk.top() == '('))
				{
					stk.pop();
				}
				else
				{
					balance = false;
				}
			}

		}
		if (!stk.empty()) balance = false;
		if (balance) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

}