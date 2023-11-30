#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, string> m;
	int n, m1;
	cin >> n >> m1;
	for (int i = 0; i < n; i++)
	{
		string address, pw;
		cin >> address >> pw;
		m[address] = pw; //없으면 새로 생기고 있으면 덮어쓰기된다.
	}
	for (int i = 0; i < m1; i++)
	{
		string address;
		cin >> address;
		auto ans = m.find(address);
		if (ans != m.end()) {
			cout << (*ans).second << "\n";
		}
	}
	return 0;
}