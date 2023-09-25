#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[101][100001] = { 0, };
vector<pair<int, int>> item;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		item.push_back({ w,v });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			//배낭의 최대무게 보다 물건의 무게가 많을때
			if (item[i - 1].first > j)
			{
				arr[i][j] = arr[i - 1][j];
				continue;
			}
			//가방에 물건을 담을때
			arr[i][j] = arr[i - 1][j - item[i - 1].first] + item[i - 1].second;
			//물건을 최대 가방 무게에 맞춰 넣었지만, 같은 무게에서 이전물품의 가치가 더 높을수 있음
			arr[i][j] = max(arr[i][j], arr[i - 1][j]);
		}
	}
	cout << arr[n][k];
	return 0;
}
// 테이블설정
// arr[i][w] -> i번 물건을 보고 w 만큼 무게를 넣었을때 최대 기대치
// i는 물품을 본 횟수, w는 넣을수 있는 가방의 무게

// 점화식
// 배낭의 최대무게보다 물건이 무거울때
// arr[i][w]= arr[i-1][w]

// 물건이 현재 가방 보다 무겁지 않을때
// arr[i][w]= arr[i-1][w-k]+아이템의 가치

// 새로운 아이템이라도 선택하지 않았을때
//arr[i][w]= arr[i-1][w]

// w라는 최대 배낭에 대해서 물건을 더했을때 가치가 
// i번째 물건에 대한 w 라는 무게의 최대 배낭보다 작을수 있기때문에 비교
// 항상 최대 이상치를 기억해가면서 비교해야한다.
// arr[i][w]= max(arr[i-1][w-k]+아이템의 가치,arr[i-1][w])