#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string way;
	int n;
	string str;

	for (int i = 0; i < t; i++)
	{
		deque<int> arr;
		bool error = false;
		cin >> way;
		cin >> n;
		cin >> str;
		bool seq = true;
		//true : front
		//false : reverse
		string input = "";
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '[' || str[j] == ']' || str[j] == ',')
			{
				if (input != "")
				{
					arr.push_back(stoi(input));
				}
				input = "";
				continue;
			}
			input = input + str[j];
		}
		for (int j = 0; j < way.length(); j++)
		{
			if (way[j] == 'R')
			{
				seq = !seq;
			}
			else
			{
				if (!arr.empty())
				{
					if (seq == true)
					{
						arr.pop_front();
					}
					else
					{
						arr.pop_back();
					}
				}
				else
				{
					error = true;
					break;
				}
			}
		}
		if (error == true)
		{
			cout << "error" << "\n";
		}
		else
		{
			cout << "[";
			if (seq == true)
			{
				for (int j = 0; j < arr.size(); j++)
				{
					cout << arr[j];
					if (arr.size() - 1 != j)
						cout << ",";
				}
			}
			else
			{
				for (int j = arr.size() - 1; j > -1; j--)
				{
					cout << arr[j];
					if (j != 0)
						cout << ",";
				}
			}
			cout << "]" << "\n";
		}

	}
	return 0;
}
//¸®¹ö½º