class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int upnumber = 0;
		int count = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (upnumber < arr[i])
			{
				count += (arr[i] - upnumber - 1);
				upnumber = upnumber + (arr[i] - upnumber - 1);
			}

			if (count >= k)
			{
				upnumber -= (count - k);
				break;
			}

			upnumber++;
		}

		if (count < k)
		{
			upnumber += (k - count);
		}
		return upnumber;

	}
};