#include <bits/stdc++.h>
using namespace std;
int arr[100001] = { 0, };
int ans = 100011;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	long long sum = 0;
	int len = 0;
	int point = 0; //0부터 시작
	while (point < n)
	{
		if (point == 0)
		{
			sum += arr[point];
			len++;
			point++;
			continue;
		}
		if ((arr[point] - arr[point - 1]) == 1) //연속된 수라면
		{
			sum += arr[point];
			len++;
			point++;
			if (sum >= s)
			{
				ans = min(ans, len);
				//뒤에 연속된다면?필요가 없음
				while (point < n)
				{
					if ((arr[point] - arr[point - 1]) == 1)point++;
					else break;
				}
				//연속이 끝나면 끝난 pointer의 값을 저장해준다.
				sum = arr[point];
				len = 1;
				point++;
			}
		}
		else //연속된 수가 아니라면
		{
			sum = arr[point];
			len = 1;
			point++;
		}
	}
	if (ans == 100011)cout << 0 << "\n";
	else cout << ans << "\n";
	return 0;
}

//증가하는 수에 대한 합으로 코드를 작성했다.
// 연속된 수들의 부분합중... -> 정렬없이 인접한 수..... 에바지 여기서 부분합을 구하고 합이 s 이상인 부분연속수열중 길이가 가장 짧은것을 구하자.