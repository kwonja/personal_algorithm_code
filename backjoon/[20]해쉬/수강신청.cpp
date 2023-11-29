#include <bits/stdc++.h>
using namespace std;
//오름차순
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
		if (student.find(id) != student.end())//존재한다면
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
		if (i == k)break; //총 수강인원보다 수강인원이 적을수도 있다
	}
	return 0;
}

//set,map을 vector로 옮겨 정렬하고 출력하는게 아주 편한방법인것 같다.