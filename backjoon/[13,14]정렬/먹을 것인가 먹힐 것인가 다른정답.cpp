#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(n + m);
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v[i] = { a, 0 };
		}
		for (int i = n; i < n + m; i++) {
			int b;
			cin >> b;
			v[i] = { b, 1 };
		}
		sort(v.begin(), v.end());
		int cnt = 0; // 현재까지 나온 b의 개수
		int ans = 0;
		for (int i = 0; i < n + m; i++) {
			if (v[i].second == 0) // 현재 보는 수가 A에 속한 수
				ans += cnt;
			else // 현재 보는 수가 B에 속한 수
				cnt++;
		}
		cout << ans << '\n';
	}
}

//이걸 진행할때 a와 b가 같을때 second 0과 1에 대해서 동일한 우선순위를 보장해줘야 b,먹히는숫자를 정확히 계산할 수 있다.
//위 문제는 테스트케이스가 위배되는게 없어서 통과했지만
// stable_sort 나 cmp 함수를 통해 second 정렬을 따로 진행해줘야 완벽한 코드라고 생각한다.