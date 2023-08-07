#include <bits/stdc++.h>
using namespace std;



void top(int n, int a, int b)
{
	if (n == 1)
	{
		cout << a << " " << b << "\n";
		return;
	}
	top(n - 1, a, 6 - a - b);
	cout << a << " " << b << "\n";
	top(n - 1, 6 - a - b, b);
}

int main()
{
	int n;
	cin >> n;
	string a = to_string(pow(2, n));
	int x = a.find('.');
	a = a.substr(0, x);
	a[a.length() - 1] -= 1;
	cout << a << "\n";
	if (n <= 20)
	{
		top(n, 1, 3);
	}
	return 0;
}
/*
int 4byte 32bit 2^31 까지 표현가능
10자리까지 표현가능

unsigned long long 최대 18,446,744,073,709,552,000
8byte 64bit 2^64 까지 표현가능

20자리 까지 사용가능

넘어가는건 string으로 처리해주는것이 좋아 보인다.
*/