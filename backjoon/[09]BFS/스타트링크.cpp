#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int dist[1000001] = { 0, };
int visited[1000001] = { 0, };
queue<int> q;
int btn[2] = { 0, };
void bfs(int x)
{
	q.push(x);
	dist[x] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			int next = cur + btn[i];
			if (next < 1 || next >f)continue;
			if (dist[next])continue; //방문했었다면 제외
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> f >> s >> g >> u >> d;
	btn[0] = u;
	btn[1] = -d;
	bfs(s);
	if (dist[g] == 0)cout << "use the stairs";
	else cout << dist[g] - 1;
	return 0;
}