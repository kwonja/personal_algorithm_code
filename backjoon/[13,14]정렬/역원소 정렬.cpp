#include <bits/stdc++.h>
using namespace std;

long long arr[10000001];
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str1;
		cin >> str1;
		while (str1.back() == '0')
		{
			str1.pop_back();
		}
		reverse(str1.begin(), str1.end());
		arr[i] = stoll(str1);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}

//stoi �� ����ϰ� �Ǹ� int ������ �Ѿ out of range ������ ����
//reverse ���̺귯���� ���� ������ ����, reverse -> #include algorithm reverse(str1.begin(),str1.end())�� ����� �����ϴ�.
//string Ŭ������ vector ó�� pop_back(),push_back() �� ���� ���̺귯���� ����� ������
//