#include <iostream>
#include <string>
#include<vector>
#include<memory.h>
#include<map>
#include<set>
using namespace std;
vector<int> dp(10000, 0);
int dig(int num)
{
	if (num <= 9)
		return num;

	if (dp[num] != 0)
		return dp[num];

	int newNum = 0;
	while (0 < num)
	{
		newNum += num % 10;
		num = num / 10;
	}

	dp[num]= dig(newNum);
	return dp[num];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		map<pair<int, pair<int, int>>,int> mymap;
		int k, m;
		scanf("%d %d", &k, &m);
		pair<int, int> pos = { 0,0 };
		int num = 1;
		int ind = 1;

		pos.second += num;
		k--;
		//k = 100;

		bool isHistory=false;
		while (k--)
		{
			//printf("%d %d\n", pos.first, pos.second);
			num = dig(num * m);

			if (isHistory == false)
			{
				auto& history = mymap[{ind % 4, { pos.first,pos.second }}];
				if (history != 0)
				{
					isHistory = true;
					int repeat = ind - history;
					k=(k) % repeat;
					/*repeat = ind - history;
					int past = (history - 1);
					k = (k - history + 1) % repeat;
					k += past;
					ind = history;*/
				}

				history = ind;
			}

			if (ind % 4 == 0)
			{
				pos.second += num;
			}
			else if (ind % 4 == 1)
			{
				pos.first += num;
			}
			else if (ind % 4 == 2)
			{
				pos.second -= num;
			}
			else if (ind % 4 == 3)
			{
				pos.first -= num;
			}

			ind++;

			

			//printf("%d %d\n", pos.first, pos.second);
		}

		
			printf("%d %d\n", pos.first, pos.second);
	}
}