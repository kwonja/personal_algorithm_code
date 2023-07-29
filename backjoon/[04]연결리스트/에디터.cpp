#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<char> arr;
	list<char>::iterator cursor; //반복자 선언
	string str;
	int M;
	cin >> str;
	for (auto i = 0; i < str.length(); i++)
	{
		arr.push_back(str[i]);
	}
	cursor = arr.end(); //맨끝에 커서가 위치하도록함
	char keyboard;
	char str2;
	cin >> M;
	while (M--)
	{
		cin >> keyboard;
		if (keyboard == 'P')
		{
			cin >> str2;
			arr.insert(cursor, str2); //그대로 끝을 가리키고 있다
		}
		else if (keyboard == 'B')
		{
			if (cursor != arr.begin())
			{
				cursor--;
				cursor = arr.erase(cursor);
			}
		}
		else if (keyboard == 'D')
		{
			if (cursor != arr.end()) cursor++;
		}
		else
		{
			if (cursor != arr.begin()) cursor--;
		}
	}
	for (auto it : arr)
	{
		cout << it;
	}


}