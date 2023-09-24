#include <bits/stdc++.h>
using namespace std;
long long arr[100001] = { 0, };
long long p[100001] = { 0, };
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	arr[0] = p[0];
	for (int i = 1; i < n; i++)
	{
		arr[i] = max(arr[i - 1] + p[i], p[i]);
	}
	cout << *max_element(arr, arr + n);
	return 0;
}

// 테이블 설정
// i번째 연속이거나 새로 시작하거나

// 점화식
// arr[i] = max (arr[i-1]+p[i],p[i])

// 초기값
// arr[0]=10