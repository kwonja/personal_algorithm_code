#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<string> entry;
	set<string> ans;
	string s, e, q;
	cin >> s >> e >> q;
	int sth, stm, eh, em, qh, qm;
	sth = stoi(s.substr(0, 2));
	stm = stoi(s.substr(3, 2));
	int ssum = sth * 60 + stm;
	eh = stoi(e.substr(0, 2));
	em = stoi(e.substr(3, 2));
	int esum = eh * 60 + em;
	qh = stoi(q.substr(0, 2));
	qm = stoi(q.substr(3, 2));
	int qsum = qh * 60 + qm;
	string time, name;
	//입력이 들어올때까지 -> 이렇게 표현할 수 도 있구나
	while (cin >> time >> name)
	{
		int h, m;
		h = stoi(time.substr(0, 2));
		m = stoi(time.substr(3, 2));
		//참석
		if (h * 60 + m <= ssum)
		{
			entry.insert(name);
		}
		else if (h * 60 + m >= esum && h * 60 + m <= qsum) //출석인정
		{
			if (entry.find(name) != entry.end()) ans.insert(name);
		}
	}
	cout << ans.size() << "\n";
	return 0;
}


//substr(pos,count) pos-> index , count는 수 count가 없으면 pos부터 맨끝까지 문자열을 가져온다 count가 초과하더라도 맨끝까지 가져온다.
//pos가 range를 벗어나면 에러가 뜬다.