#include <bits/stdc++.h>
using namespace std;

int funz(int n, int r, int c)
{
	if (n == 0)return 0;
	int half = 1 << (n - 1);
	if (r < half && c < half) return funz(n - 1, r, c);
	if (r < half && c >= half) return half * half + funz(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + funz(n - 1, r - half, c);
	if (r >= half && c >= half) return 3 * half * half + funz(n - 1, r - half, c - half);

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << funz(n, r, c);

	return 0;
}

//base condition n==0 일때 return 0
// 1번일때
// 2번일때
// 3번일때
// 4번일때
// 각각나눠서 진행하면 좋다.