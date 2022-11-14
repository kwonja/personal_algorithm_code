#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int idx = 0;
	int sum = 0;
	deque<int> q;

	while (1)
	{
		int tmp = truck_weights[idx];
		if (idx == truck_weights.size())
		{
			answer += bridge_length;
			break;
		}

		answer++; //시간증가

		if (q.size() == bridge_length)
		{
			sum -= q.front(); //지나간 무게를 빼준다.
			q.pop_front(); //지나간 트럭을 빼낸다.
		}

		if (sum + tmp <= weight)
		{
			sum += tmp;
			q.push_back(tmp);
			idx++;
		}
		else
		{
			q.push_back(0); //무게가 넘칠때 0을 통해
		}
	}
	return answer;
}