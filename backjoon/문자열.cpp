#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	int MIN = 9999;
	int min_element = 0;
	int count = 0;
	for (int i = 0; i <= (str2.length() - str1.length()); i++)
	{
		count = 0;
		for (int j = 0; j < str1.size(); j++)
		{
			if (str1[j] != str2[j + i])count++;
		}
		MIN = min(MIN, count);
	}
	cout << MIN;
}