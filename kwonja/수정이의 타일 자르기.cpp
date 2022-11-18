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
		sort(need.begin(), need.end(), compare); //내림차순정렬
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
					break; //한번 분할하고 뒤에서 더 분할하게되는 경우 방지, 분할한다 == 원하는 타일을 찾았다
				}

			}
			if (check == 0) //분할에 성공하지 못했을때
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


//내가 생각하는 핵심은 자르고 난 나머지들을 백터로 저장하는것이다!
//후에 분할을 했으면 break문으로 다음 필요한 타일로 넘어가는 과정을 진행해줘야한다.