#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<char> arr;
	list<char>::iterator cursor; //�ݺ��� ����
	string str;
	int M;
	cin >> str;
	for (auto i = 0; i < str.length(); i++)
	{
		arr.push_back(str[i]);
	}
	cursor = arr.end(); //�ǳ��� Ŀ���� ��ġ�ϵ�����
	char keyboard;
	char str2;
	cin >> M;
	while (M--)
	{
		cin >> keyboard;
		if (keyboard == 'P')
		{
			cin >> str2;
			arr.insert(cursor, str2); //�״�� ���� ����Ű�� �ִ�
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