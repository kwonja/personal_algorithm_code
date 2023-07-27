#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, input;
	vector<int> stack;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> input;
		if (input == 0) stack.pop_back();
		else stack.push_back(input);
	}
	long long sum = 0;
	for (auto i : stack)
	{
		sum += i;
	}
	cout << sum;
	return 0;
}