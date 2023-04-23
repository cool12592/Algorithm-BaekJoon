#include <iostream>
#include <string>
#include<vector>
#include<memory.h>
#include<map>
#include<set>
using namespace std;

//int last;
vector<int> vec;
int ans = 0;
//void toggle(int ind);
//void changeZero(int start, int end);
//
//void toggle(int ind)
//{
//	ans++;
//	if (ind == last)
//		vec[ind] = !vec[ind];
//	else
//	{
//		if (vec[ind + 1] == false)
//			toggle(ind + 1);
//		changeZero(ind + 2, last);
//		vec[ind] = !vec[ind];
//	}
//
//}
//
//void changeZero(int start,int end)
//{
//	if (end < start)
//		return;
//
//	for (int i = start; i <= end; i++)
//	{
//		if (vec[i] == true)
//			toggle(i);
//	}
//
//}

int myMultiple(int ind)
{
	int num = 1;

	while (ind--)
	{
		num *= 2;
	}

	num = num - 1;
	return num;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		ans = 0;
		vec.clear();
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '1')
				vec.push_back(1);
			else
				vec.push_back(0);
		}

		bool plus = true;
		for (int i = 0; i < vec.size(); i++)
		{
			int temp;
			if (vec[i] == 1)
			{
				temp = myMultiple(vec.size() - i);

				if (plus)
				{
					ans += temp;
					plus = !plus;
				}
				else
				{
					ans -= temp;
					plus = !plus;
				}
			}
			

		}

		cout << ans<<"\n";
	}
	return 0;
}