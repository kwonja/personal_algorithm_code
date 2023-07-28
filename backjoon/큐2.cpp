#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	queue<int> q;
	string op;

	for (int i = 0; i < n; i++)
	{
		cin >> op;
		if (op == "push")
		{
			int input;
			cin >> input;
			q.push(input);
		}
		else if (op == "pop")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (op == "size")
		{
			cout << q.size() << "\n";
		}
		else if (op == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (op == "front")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
			}
		}
		else if (op == "back")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
	}
	return 0;
}

//����� �����ϴ°�� c++�� c stream�� ���� �ð��� ���� �ɸ��� �ִ�
//���� �Էµ� ���̹����� ���ۻ��ð��� ����ġ ������