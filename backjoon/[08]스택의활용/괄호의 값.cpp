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

//���ڸ� ���ϴ°��� top���̺귯���� ���� �����߾��µ�
//�׷��ԵǸ� ����ó���� ���� ������ϴ� �����߻�
//�Ʒ� �ΰ����� �������
// ������ ��������� ] ����
// ������ �Ⱥ���ִµ� top�� ��ȣ���� �ƴҶ� ����
// ��ȣ���� �´ٸ� pop
// �������� ���ÿ� �����ִٸ� ����