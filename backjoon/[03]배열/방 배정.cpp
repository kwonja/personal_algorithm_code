#include <iostream>
#include <vector>
#include<set>
#include<map>
#include <string>
using namespace std;

int m[7] = { 0, };
int w[7] = { 0, };
int main(void)
{
	int count = 0;
	int n, k, s, y;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;

		if (s == 1) //남자
		{
			m[y]++;
		}
		else //여자
		{
			w[y]++;
		}
	}
	for (int i = 1; i < 7; i++)
	{
		if (m[i])
		{
			if (m[i] % k)
			{
				count = count + m[i] / k + 1;
			}
			else
			{
				count = count + m[i] / k;
			}
		}

		if (w[i])
		{
			if (w[i] % k)
			{
				count = count + w[i] / k + 1;
			}
			else
			{
				count = count + w[i] / k;
			}
		}
	}
	cout << count;

	return 0;
}