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

//���̰� ª�� �ͺ��� length ���
//���̰� ������ ����������
//�ߺ��� �ܾ� -> ���ĵ� ����(sort��)���� erase unique�� ����ؼ� �ߺ��� ã�� �����Ѵ�. 