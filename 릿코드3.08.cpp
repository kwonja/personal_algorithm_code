typedef long long ll;
class Solution {
public:
	int func1(vector<int>& time, int totalTrips, ll mid)
	{
		ll total = 0;
		for (ll i = 0; i < time.size(); i++)
		{
			total += (mid / time[i]);
		}
		if (total < totalTrips) return 0;
		else return 1;
	}

	long long minimumTime(vector<int>& time, int totalTrips) {

		ll s = 0;
		ll e = (ll)totalTrips*(ll)time[0];
		ll mid = (e + s) / 2;
		ll answer = 0;
		while (s <= e)
		{
			if (func1(time, totalTrips, mid))
			{
				answer = mid;
				e = mid - 1;
			}
			else
			{
				s = mid + 1;
			}
			mid = (e + s) / 2;
		}
		return answer;
	}
};