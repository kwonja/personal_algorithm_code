#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;
int Max = 0;
char arr[20][20] = { 0, };

void  func1(int x, int y, vector<char> item, int r, int c)
{
	if ((x < 0) || (y < 0) || (x >= r) || (y >= c))
	{
		if (Max < item.size())
		{
			Max = item.size();
		}
		return;
	}
	if (!item.empty())
	{
		for (int i = 0; i < item.size(); i++)
		{
			if (arr[x][y] == item[i])
			{
				if (Max < item.size())
				{
					Max = item.size();
				}
				return;
			}
		}
	}
	//상품등록
	item.push_back(arr[x][y]);
	//왼쪽
	func1(x, y - 1, item, r, c);
	//오른쪽
	func1(x, y + 1, item, r, c);
	//아래
	func1(x - 1, y, item, r, c);
	//위
	func1(x + 1, y, item, r, c);

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int r, c;
		char temp;
		Max = 0;
		cin >> r >> c;
		for (int j = 0; j < r; j++) //배열생성
		{
			for (int g = 0; g < c; g++)
			{
				cin >> temp;
				arr[j][g] = temp;
			}
		}

		vector<char> item;
		func1(0, 0, item, r, c);
		cout << "#" << i + 1 << " " << Max << endl;

	}
	return 0;
}