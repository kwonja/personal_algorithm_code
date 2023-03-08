class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		int minitime = 1;
		int total = 0;

		while (1)
		{
			total = 0;
			for (int i = 0; i < time.size(); i++)
			{
				total += (minitime / time[i]);
			}
			if (totalTrips <= total)
			{
				break;
			}
			minitime++;
		}
		return minitime;
	}
};