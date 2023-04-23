#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, l;
	cin >> n>>l;
	vector<pair<int,int>> vec;
	int a=0, b=0;
	int longdist1 = 0;
	int longdist2 = 2000000000;

	int i = 0;
	int len = n;
	while (len--)
	{
		i++;
		int num;
		cin >> num;
		if (num < 0)
		{
			b++;
			num *= -1;
			if (longdist1 < num)
			{
				longdist1 = num;
			}
		}
		else
		{
			a++;

			if (longdist2 > num)
			{
				longdist2 = num;
			}
		}
		vec.push_back({ num,i });

	}
	sort(vec.begin(), vec.end());

	int ansnumber;
	int anstime;
	int aa = l - longdist2;
	int bb = longdist1;
	if (aa > bb) 
	{
		anstime = aa; //오른쪽으로향하는애중 제일 왼쪽에있는
		ansnumber = vec[n - a].second;
	}
	else
	{
		anstime = bb;
		ansnumber = vec[b-1].second;
	}
	cout << ansnumber << " " << anstime;
	return 0;
}