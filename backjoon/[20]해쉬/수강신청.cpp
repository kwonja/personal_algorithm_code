#include <bits/stdc++.h>
using namespace std;
//��������
bool cmp(pair<string, int> &a, pair<string, int> &b)
{
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, l;
	cin >> k >> l;
	map<string, int> student;
	for (int i = 0; i < l; i++)
	{
		string id;
		cin >> id;
		if (student.find(id) != student.end())//�����Ѵٸ�
		{
			student.erase(id);
		}
		student.insert({ id,i });
	}
	vector<pair<string, int>> ans(student.begin(), student.end());
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 1; i <= ans.size(); i++)
	{
		cout << ans[i - 1].first << "\n";
		if (i == k)break; //�� �����ο����� �����ο��� �������� �ִ�
	}
	return 0;
}

//set,map�� vector�� �Ű� �����ϰ� ����ϴ°� ���� ���ѹ���ΰ� ����.