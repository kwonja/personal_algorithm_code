#include <bits/stdc++.h>
using namespace std;
int arr[100001] = { 0, };
int ans = 2000000001;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st, ed;
	st = ed = 0; //
	while (ed != n)
	{
		if (arr[ed] - arr[st] < m)ed++;
		else //m 보다 크거나 같을때
		{
			ans = min(ans, arr[ed] - arr[st]);
			st++;
		}
	}
	cout << ans << "\n";
	return 0;
}

//구하는것이 최소값이기에 st, ed의 차이가 m보다 큰 순간이후는 필요없다
//arr[ed]-arr[st]>=m 을 만족하면 st을 올려 차이를 비교하고 m보다 크면서 더 작은값이면 저장한다.
//m보다 차이가 작으면 ed를 뒤로 보내면서 최대 O(2n)의 시간복잡도를 가진다.
//일일이 반복하는것이 아닌 커서를 옮기면서 효율적으로 탐색할 수 있다.