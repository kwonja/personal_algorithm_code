#include <bits/stdc++.h>
using namespace std;
int n;
long long  arr[91][2] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	arr[1][1] = 1;
	arr[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}
	cout << arr[n][0] + arr[n][1];
	return 0;
}

//테이블 설정
//arr[i][j] 끝이 j일때 이친수 개수

//점화식
// arr[i][0] i번째 이친수인데 0으로 끝남
// arr[i][1] i번째 이친수인데 1으로 끝남

// arr[i][0] = arr[i-1][0]+arr[i-1][1]
// arr[i][1] = arr[i-1][0]

//초기값
// arr[1][1]=1;
// arr[1][0]=0;

//보통 dp값은 n이 커지게되면
//int를 넘는경우가 많다.