using namespace std;

long long solution(int price, int money, int count)
{

	long long sum = 0;
	long long i = 1;

	while (i <= count)
	{
		sum = sum + (price*i);
		i++;
	}
	if (sum <= money)
	{
		return 0;
	}
	else
	{
		return (sum - money);
	}
	return -1;
}