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

//stoi 를 사용하게 되면 int 범위를 넘어서 out of range 에러가 생성
//reverse 라이브러리를 통해 역정렬 가능, reverse -> #include algorithm reverse(str1.begin(),str1.end())로 사용이 가능하다.
//string 클래스는 vector 처럼 pop_back(),push_back() 등 벡터 라이브러리를 사용할 수있음
//