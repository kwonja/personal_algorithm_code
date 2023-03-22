class Solution {
public:
	long long zeroFilledSubarray(vector<int>& nums) {

		long long sum = 0;
		long long count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				sum = sum + (++count);
			}
			else
			{
				count = 0;
			}
		}
		return sum;
	}
};