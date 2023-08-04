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

	cout << (1 << n) - 1 << "\n"; //2^20까지 int로 표현이 가능하다.
	if (n <= 20)
	{
		top(n, 1, 3);
	}
	return 0;
}