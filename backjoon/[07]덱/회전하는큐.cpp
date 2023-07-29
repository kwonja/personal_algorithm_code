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
				//�������� ��ĭ
				deq.push_back(deq.front());
				deq.pop_front();
				count++;
			}
		}
		else
		{
			for (int g = 0; g < (deq.size() - target); g++)
			{
				//���������� ��ĭ
				deq.push_front(deq.back());
				deq.pop_back();
				count++;
			}
		}
		//����
		deq.front();
		deq.pop_front();
	}
	cout << count;

	return 0;
}

//O(n)�� �뷫 n�� õ��������
//O(n^2)�� �뷫 n�� 5õ�������϶�
//O(n^2)�� �뷫 n�� 5�鰳 �����϶�
//1�ʾȿ� ���ư���
//�ش� ������ 2���� �ð��� �־����� n�� 50���϶� n^3 Ǯ�̽��̶� ����ϴ°��� �� �� �־���.