#include <bits/stdc++.h>
using namespace std;
string str;
int sign = 1;
int answer, tmp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			answer += tmp * sign;
			if (str[i] == '-')sign = -1;
			tmp = 0;
		}
		else
		{
			tmp = tmp * 10;
			tmp += (str[i] - '0');
		}
	}
	answer += tmp * sign;
	cout << answer;
	return 0;
}

//최소값을 만드려면
//-가 나온뒤로 +가 되는걸 묶어주면 된다.

//그리디의 핵심은 가장 최적인 답을 근시안적으로 택하는 것