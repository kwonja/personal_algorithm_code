#include <bits/stdc++.h>
using namespace std;

int arr[20] = { 0, };
int n, s;
int cnt = 0;

void func(int depth, int sum)
{
	if (depth == n) {
		if (sum == s) cnt++;
		return;
	}

	func(depth + 1, sum + arr[depth]); //���ϰ�
	func(depth + 1, sum); //�ȴ��ϰ�

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int input;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (s == 0)cnt--; //0�϶��� ����
	func(0, 0);

	cout << cnt;

	return 0;
}