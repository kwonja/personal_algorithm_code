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
				if (stk.empty() || stk.top() !='(')
				{
					error = true;
					break;
				}
				if (str[i - 1] == '(') count += c;
				stk.pop();
				c = c / 2;
		}
		else if (str[i] == ']')
		{
			if (stk.empty() || stk.top() != '[')
			{
				error = true;
				break;
			}
			if (str[i - 1] == '[') count += c;
			stk.pop();
			c = c / 3;
		}
	}
	if (!stk.empty()) error = true;

	if (error) cout << 0;
	else cout << count;
	return 0;
}

//숫자를 더하는것을 top라이브러리를 통해 구현했었는데
//그렇게되면 예외처리를 따로 해줘야하는 단점발생
//아래 두가지를 기억하자
// 스택이 비어있을때 ] 에러
// 스택이 안비어있는데 top이 괄호쌍이 아닐때 에러
// 괄호쌍이 맞다면 pop
// 마지막에 스택에 남아있다면 에러