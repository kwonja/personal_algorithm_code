#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> deq;
	int n, m, k;
	int count = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		deq.push_back(i);
	}
	int target = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> k;

		for (int j = 0; j < deq.size(); j++)
		{
			if (deq[j] == k) target = j;
		}
		if (target < deq.size() - target)
		{
			for (int g = 0; g < target; g++)
			{
				//왼쪽으로 한칸
				deq.push_back(deq.front());
				deq.pop_front();
				count++;
			}
		}
		else
		{
			for (int g = 0; g < (deq.size() - target); g++)
			{
				//오른쪽으로 한칸
				deq.push_front(deq.back());
				deq.pop_back();
				count++;
			}
		}
		//추출
		deq.front();
		deq.pop_front();
	}
	cout << count;

	return 0;
}

//O(n)은 대략 n이 천만개이하
//O(n^2)은 대략 n이 5천개이하일때
//O(n^2)은 대략 n이 5백개 이하일때
//1초안에 돌아간다
//해당 문제는 2초의 시간이 주어지고 n이 50이하라서 n^3 풀이식이라도 통과하는것을 볼 수 있었다.