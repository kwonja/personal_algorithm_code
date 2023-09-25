#include <bits/stdc++.h>
using namespace std;
int n;

int arr[1000] = { 0, };
int s[1000] = { 0, };
int sum = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	arr[0] = s[0]; //1등
	for (int i = 1; i < n; i++)
	{
		arr[i] = arr[i - 1] + s[i];
	}
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	cout << sum;
	return 0;
}
//테이블
//최소값을 구해야하기때문에
//가장 빨리끝나는사람들이 앞에서 끝내야한다.
//-> 가장 작은 수가 반복해야 최소값이 된다.
//arr[i] i번째까지 걸리는 시간
//arr[i]=arr[i]+a[i]