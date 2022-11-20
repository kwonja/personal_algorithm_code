#include <string>
#include <vector>

using namespace std;
vector<int> arr;
int Max = 0;
int Min = 0;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	for (int i = 0; i < win_nums.size(); i++)
	{
		arr.push_back(0);
	}
	for (int i = 0; i < lottos.size(); i++)
	{
		if (lottos[i] == 0)
		{
			Max++;
			continue;
		}
		for (int j = 0; j < lottos.size(); j++)
		{
			if ((lottos[i] == win_nums[j]) && (arr[j] == 0))
			{
				Min++;
				Max++;
				arr[j] = 1;
			}
		}
	}
	switch (Max)
	{
	case 6:
		answer.push_back(1);
		break;
	case 5:
		answer.push_back(2);
		break;
	case 4:
		answer.push_back(3);
		break;
	case 3:
		answer.push_back(4);
		break;
	case 2:
		answer.push_back(5);
		break;
	default:
		answer.push_back(6);
	}
	switch (Min)
	{
	case 6:
		answer.push_back(1);
		break;
	case 5:
		answer.push_back(2);
		break;
	case 4:
		answer.push_back(3);
		break;
	case 3:
		answer.push_back(4);
		break;
	case 2:
		answer.push_back(5);
		break;
	default:
		answer.push_back(6);
	}
	return answer;
}