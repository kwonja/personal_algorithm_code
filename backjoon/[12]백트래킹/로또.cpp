#include <bits/stdc++.h>
using namespace std;
int k;

int arr[50] = { 0, };
int c[50] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> k;
		if (k == 0)break;
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}
		for (int i = 6; i < k; i++)
		{
			c[i] = 1;
		}
		do {
			for (int i = 0; i < k; i++)
			{
				if (c[i] == 0) cout << arr[i] << " ";
			}
			cout << "\n";
		} while (next_permutation(c, c + k));
		cout << "\n";
		fill(c, c + k, 0);
	}

	return 0;
}