#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string t;
int success;
void func(string str)
{
	if (str.length() == s.length())
	{
		if (str == s)
		{
			success = 1;
			return;
		}
		else return;
	}
	if (str.back() == 'A')
	{

		string str2 = str;
		str2.pop_back();
		func(str2);
	}
	if (str.front() == 'B')
	{
		reverse(str.begin(), str.end());
		str.pop_back();
		func(str);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	func(t);
	if (success)cout << "1";
	else cout << "0";

	return 0;
}