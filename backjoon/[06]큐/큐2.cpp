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

//출력을 많이하는경우 c++과 c stream에 대한 시간이 많이 걸릴수 있다
//또한 입력도 많이받을때 버퍼사용시간도 만만치 않은듯