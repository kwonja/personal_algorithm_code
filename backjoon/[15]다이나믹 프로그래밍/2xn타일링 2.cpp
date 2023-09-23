#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 2]) % 10007;
	}
	cout << arr[n];
	return 0;
}

//테이블 설정
//arr[i] i번째까지 타일의 경우의 수

//점화식
// arr[i]= arr[i-2]*2 + arr[i-1] 

//초기값
// arr[1]=1; arr[2]=3;