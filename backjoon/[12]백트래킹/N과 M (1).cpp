#include <bits/stdc++.h>
using namespace std;
int visited[9] = { 0, };
int arr[9] = { 0, }; //0�� �ȵ���ִ°�
int n, m;
void func1(int n, int x, int seq)
{
	if (x == 0)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 1)continue;
		visited[i] = 1; //�湮
		arr[seq] = i;
		func1(n, x - 1, seq + 1);
		visited[i] = 0; //�� ���ƿ��� ���� �湮�� ��������
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func1(n, m, 0);
	return 0;
}

/*
�迭�� ���ڸ� �־���� ����Ѵٴ� ������ ���� ������
*/
