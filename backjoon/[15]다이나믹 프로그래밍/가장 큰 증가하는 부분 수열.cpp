#include <bits/stdc++.h>
using namespace std;
int n;
int item[1000] = { 0, };
int arr[1001] = { 0, };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (item[i] > item[j]) arr[i] = max(arr[i], arr[j] + item[i]);
		}
		//item[i]가 부분수열의 시작일때
		if (arr[i] == 0) arr[i] = item[i];
	}
	cout << *max_element(arr, arr + n);
	return 0;
}


// 테이블 설정
// arr[i] i번째 물품에 대한 최대 부분 수열의 합

//점화식
//arr[i]= if(i=0;i<=i-1) 까지 아이템을 확인하면서
//i=0 부터item[i-1] 연속된 합중 최대를 대입

//값을 비교후 해당 아이템이 부분수열의 시작때 arr[i]=item[i]

//증가하는 부분순열이라는 이름을 생각해야했다...ㅠㅠ