#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10] = { 0, };

	int n;
	cin >> n;
	while (n)
	{
		if (n % 10 == 6)
		{
			arr[9]++;
		}
		else
		{
			arr[n % 10]++;
		}
		n = n / 10;
	}
	arr[9] = (arr[9] + 1) / 2;
	cout << *max_element(arr, arr + 10) << "\n";
}