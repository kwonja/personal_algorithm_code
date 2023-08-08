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

	cout << (1 << n) - 1 << "\n";
	if (n <= 20)
	{
		top(n, 1, 3);
	}
	return 0;
}
//2^20까지 int로 표현이 가능하다.
/*
n번째 하노이탑을 옮기는 방법을 재귀적으로 생각해보자

1 2 3 이 있다고할때

n-1개의 탑을 2번으로 옮긴다
n번째 탑을 3번으로 옮긴다
2번에 있던 n-1번째 탑을 3번으로 옮긴다.

1은 옮겨진다
k가 옮겨질때 k+1도 옮겨진다.
귀납법이 성립하기때문에 참이 된다.
*/