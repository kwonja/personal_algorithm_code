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

//i-1�� ����ó������ ����Ҽ� �ִ� ������ �������� �ݵ��()�̷��� �踷��Ⱑ �����Ѵٰ� �߱⶧���� ���� �������� ()�� �����ϱ⶧����
//)�� �ܵ����� ���� �����°�찡 ���ٰ� �� �� �־���.