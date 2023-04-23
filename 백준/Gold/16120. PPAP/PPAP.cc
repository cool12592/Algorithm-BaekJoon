#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	string str;
	string sol;

	cin >> str;

	
	for (int i = 0; i < str.size(); i++)
	{
		if (sol.size() >= 3 && str[i] == 'P')
		{
			int n = sol.size();
			if (sol[n - 1] == 'A' && sol[n - 2] == 'P' && sol[n - 3] == 'P')
			{
				sol.pop_back();
				sol.pop_back();
				sol.pop_back();
			}
		}
		sol += str[i];
	}
	if (sol == "P")
		cout << "PPAP";
	else
		cout << "NP";
	return 0;
}