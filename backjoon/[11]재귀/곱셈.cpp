#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll POW(ll a, ll b, ll m)
{
	if (b == 1)return a % m; //1일때
	ll result = POW(a, b / 2, m);
	result = result * result %m;
	if (b % 2 == 0)return result; //짝수일때
	return result * a%m; //1이 아닌 홀수일때
}


int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);

}