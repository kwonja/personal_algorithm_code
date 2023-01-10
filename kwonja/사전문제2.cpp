#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long N;
		long long Answer = 0;
		vector<int> arr;
		int check = 1;
		int x, y;
		cin >> N >> x >> y;
		int h = 1;
		while (N != 0)
		{
			int temp = N % 10;
			if (temp > y)
			{
				for (int j = 0; j < arr.size(); j++)
				{
					arr[j] = y;
				}
				arr.push_back(y);
			}
			else if (temp == y)
			{
				arr.push_back(y);
			}
			else if (temp > x)
			{
				for (int j = 0; j < arr.size(); j++)
				{
					arr[j] = y;
				}
				arr.push_back(x);
			}
			else if (temp == x)
			{
				if ((arr.size() != 0) && (arr[arr.size() - 1] == -1)) //뒤는작고 같을때
				{
					for (int j = 0; j < arr.size(); j++)
					{
						arr[j] = y;
					}
				}
				else
				{
					arr.push_back(x);
				}
			}
			else
			{
				if (arr.size() != 0)
				{
					for (int j = 0; j < arr.size(); j++)
					{
						arr[j] = y;
					}
				}
				arr.push_back(-1);
			}
			N = N / 10;
		}
		cout << "#" << i + 1 << " ";
		for (int j = arr.size() - 1; j >= 0; j--)
		{
			if ((arr[j] == -1) && (arr.size() != 1)) //맨처음 -1일때
			{
				continue;
			}
			if (arr[arr.size() - 1] == 0)
			{
				cout << -1 << endl; //N이 0일때
				check = 0;
				break;
			}
			if (j == 0)
			{
				Answer += arr[j]; //1의 자리
			}
			else
			{
				Answer += (arr[j] * pow(10, j));
			}
		}
		if (check == 0) continue;
		cout << Answer << endl;

	}
	return 0;
}