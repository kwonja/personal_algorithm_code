#include <iostream>
#include <vector>
#include<set>
#include<map>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string name, stat;
	map<string, int, greater<> > arr;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> stat;
		if (stat == "enter")
		{
			arr[name] = 0;
		}
		else
		{
			arr[name] = 1;
		}
	}
	for (auto iter : arr)
	{
		if (iter.second == 0)
		{
			cout << iter.first << '\n';
		}
	}

	return 0;
}