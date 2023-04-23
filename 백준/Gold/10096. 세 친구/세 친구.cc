#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<string>
using namespace std;


int main()
{

	int n;
	cin >> n;
	string str;
	cin >> str;

	if (n % 2 == 0)
	{
		cout << "NOT POSSIBLE";
		return 0;
	}
	int mid = n / 2 ;
	string str1 = str.substr(0, mid); //여기가짧음
	string str2 = str.substr(mid, mid + 1);
	string ans = "";
	int j = 0;
	int cnt = 0;
	for (int i = 0; i < mid; i++)
	{

		if (str1[i] != str2[j])
		{
			if (cnt == 0)
			{
				cnt = 1;
				j++;
				i--;
				continue;
			}
			else
			{
				cnt = -1;
				break;
			}
		}
		j++;
	}
	if (cnt != -1)
	{
		ans = str1;
	}

	
	{
		string str3 = str.substr(0, mid + 1); //여기가김
		string str4 = str.substr(mid + 1, mid); //여기가짧음

		int j = 0;
		int cnt = 0;
		for (int i = 0; i < mid; i++)
		{

			if (str4[i] != str3[j])
			{
				if (cnt == 0)
				{
					cnt = 1;
					j++;
					i--;
					continue;
				}
				else
				{
					cnt = -1;
					break;
				}
			}
			j++;
		}
		if (cnt != -1)
		{
			if (ans.size() != 0 && ans != str4)
			{
				cout << "NOT UNIQUE";
				return 0;
			}
			ans = str4;
			
		}
	}
	if (ans.size() != 0)
		cout << ans;
	else
		cout << "NOT POSSIBLE";
	return 0;
}