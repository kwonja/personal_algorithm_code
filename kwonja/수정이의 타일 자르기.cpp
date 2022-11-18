#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}
int main(void)
{
	int t, tmp;
	int n, m;
	int count = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		vector<int> need;
		vector<pair<pair<int, int>, bool>> leavesquare;
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			need.push_back(pow(2, tmp));
		}
		sort(need.begin(), need.end(), compare); //������������
		leavesquare.push_back(make_pair(make_pair(m, m), false));
		count = 1;
		for (int j = 0; j < need.size(); j++)
		{
			int len = need[j];
			int check = 0;
			for (int g = 0; g < leavesquare.size(); g++)
			{
				if (leavesquare[g].second == true) continue;

				int x = leavesquare[g].first.first;
				int y = leavesquare[g].first.second;

				if ((x >= len) && (y >= len))
				{
					leavesquare[g].second = true;
					check = 1;
					leavesquare.push_back(make_pair(make_pair(x, (y - len)), false));
					leavesquare.push_back(make_pair(make_pair(x - len, len), false));
					break; //�ѹ� �����ϰ� �ڿ��� �� �����ϰԵǴ� ��� ����, �����Ѵ� == ���ϴ� Ÿ���� ã�Ҵ�
				}

			}
			if (check == 0) //���ҿ� �������� ��������
			{
				leavesquare.push_back(make_pair(make_pair(m, (m - len)), false));
				leavesquare.push_back(make_pair(make_pair(m - len, len), false));
				count++;
			}
		}
		cout << "#" << i + 1 << " " << count << endl;
	}
	return 0;
}


//���� �����ϴ� �ٽ��� �ڸ��� �� ���������� ���ͷ� �����ϴ°��̴�!
//�Ŀ� ������ ������ break������ ���� �ʿ��� Ÿ�Ϸ� �Ѿ�� ������ ����������Ѵ�.