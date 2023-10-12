#include <bits/stdc++.h>
using namespace std;
int n;
bool cmp(const string &str1, const string &str2)
{
	if (str1.length() == str2.length())
	{
		return str1 < str2;
	}
	return str1.length() < str2.length();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<string> strarr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> strarr[i];
	}
	sort(strarr.begin(), strarr.end(), cmp);
	strarr.erase(unique(strarr.begin(), strarr.end()), strarr.end());

	for (auto i : strarr)
	{
		cout << i << "\n";
	}
	return 0;
}

//길이가 짧은 것부터 length 사용
//길이가 같으면 사전순으로
//중복된 단어 -> 정렬된 상태(sort후)에서 erase unique를 사용해서 중복을 찾고 제거한다. 