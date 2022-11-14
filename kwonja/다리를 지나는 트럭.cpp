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

		answer++; //�ð�����

		if (q.size() == bridge_length)
		{
			sum -= q.front(); //������ ���Ը� ���ش�.
			q.pop_front(); //������ Ʈ���� ������.
		}

		if (sum + tmp <= weight)
		{
			sum += tmp;
			q.push_back(tmp);
			idx++;
		}
		else
		{
			q.push_back(0); //���԰� ��ĥ�� 0�� ����
		}
	}
	return answer;
}