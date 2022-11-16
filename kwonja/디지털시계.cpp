#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int t;
	string str, str2;

	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		cin >> str;
		cin >> str2;
		int h1 = ((int)(str[0]) - 48) * 10;
		h1 = h1 + ((int)str[1] - 48);

		int m1 = ((int)(str[3]) - 48) * 10;
		m1 = m1 + ((int)str[4] - 48);

		int s1 = ((int)(str[6]) - 48) * 10;
		s1 = s1 + ((int)str[7] - 48);

		int h2 = ((int)(str2[0]) - 48) * 10;
		h2 = h2 + ((int)str2[1] - 48);

		int m2 = ((int)(str2[3]) - 48) * 10;
		m2 = m2 + ((int)str2[4] - 48);

		int s2 = ((int)(str2[6]) - 48) * 10;
		s2 = s2 + ((int)str2[7] - 48);

		int start = h1 * 10000 + m1 * 100 + s1; //시작 숫자
		int end = h2 * 10000 + m2 * 100 + s2; //끝 숫자

		if ((start % 3) == 0)count++; //처음값

		while (start != end)
		{
			s1++;
			if (s1 == 60)
			{
				m1++;
				s1 = 0;
				if (m1 == 60)
				{
					h1++;
					m1 = 0;
					if (h1 == 24)
					{
						h1 = 0;
					}
				}
			}
			start = h1 * 10000 + m1 * 100 + s1;
			if ((start % 3) == 0)count++;
		}
		cout << count << endl;
	}
	return 0;
}