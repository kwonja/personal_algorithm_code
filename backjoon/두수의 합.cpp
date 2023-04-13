#include <iostream>
#include <vector>
#include<set>
#include<map>
#include <string>
using namespace std;

long long check[10000001] = { 0, };
int main(void)
{
	long long n, input, x;
	cin >> n;
	vector<long long> arr;
	int count = 0;
	for (long i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	cin >> x;

	for (long i = 0; i < n; i++)
	{
		if (x > arr[i])
		{
			if (check[x - arr[i]])
			{
				count++;
			}
		}
		check[arr[i]] = 1; //있다는것을 확인
	}
	cout << count << endl;


	return 0;
}