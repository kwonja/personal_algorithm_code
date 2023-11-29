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
		if (ans.second)cout << ans.first << "\n";
	}
	return 0;
}

//map보다 set이 메모리적으로 효율이 좋기때문에
//set을 사용하는 방법도 좋아 보인다.
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string name, log;
		cin >> name >> log;
		if (log == "enter") s.insert(name);
		else s.erase(name);
	}
	vector<string> ans(s.begin(), s.end());
	sort(ans.begin(), ans.end(), greater<string>());
	for (auto x : ans) cout << x << '\n';
}