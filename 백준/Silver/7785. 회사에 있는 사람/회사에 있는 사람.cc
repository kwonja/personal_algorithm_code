#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, int, greater<string>> people;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, input;
		cin >> name >> input;
		if (input == "enter")
		{
			people[name] = 1;
		}
		else
		{
			people[name] = 0;
		}
	}
	for (auto ans : people)
	{
		if(ans.second)cout << ans.first << "\n";
	}
	return 0;            
}