#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visited[1001] = { 0, };
queue<int> q;
int num = 0;

void bfs(int start)
{
		q.push(start);
		visited[start] = 1;
		while (!q.empty())
		{
			int cur = q.front();
			cout << cur << " ";
			q.pop();
			for (int j = 0; j < adj[cur].size(); j++)
			{
				if (visited[adj[cur][j]])continue;
				q.push(adj[cur][j]);
				visited[adj[cur][j]] = 1;
			}
		}
		cout << "\n";
}
void dfs(int start)
{
	cout << start << " ";
	visited[start] = 1;
	for (int j = 0; j < adj[start].size(); j++)
	{
		if (visited[adj[start][j]])continue;
		dfs(adj[start][j]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x); //그래프 인접리스트 형태로 구성
	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(v);
	cout << "\n";
	for (int i = 0; i < 1001; i++)visited[i] = 0;
	bfs(v);

	return 0;
}