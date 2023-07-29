#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count = 0;
	int high = 0;

	stack<char> stk;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			stk.push(str[i]);
			high++;
		}
		else if (str[i - 1] == '(' && str[i] == ')')
		{
			high--;
			stk.pop();
			count += high;
		}
		else if (str[i] == ')')
		{
			high--;
			stk.pop();
			count++;
		}
	}
	cout << count;
}

//i-1을 예외처리없이 사용할수 있는 이유는 문제에서 반드시()이렇게 쇠막대기가 존재한다고 했기때문에 또한 레이저도 ()게 존재하기때문에
//)에 단독으로 먼저 나오는경우가 없다고 볼 수 있었다.