#include<iostream>
#include <vector>

using namespace std;

string mymultiple(string str, int multi)
{
	string outStr;
	for (int i = 0; i < multi; i++)
	{
		outStr += str;
	}
	return outStr;
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	string str;
	cin >> str;

	//이번차례 문자열이 si [이번문자 +지금까지나온세트] =>세트 이걸 ai번반복

	int ind = 0;
	vector<char>s;
	vector<int>a;
	string procceed;

	while (ind < str.size())
	{
		char now_char = str[ind];
		string now_pattern = now_char + procceed;
		int search_ind = 0;
		int multiple = 0;
		for (int i = ind; i < str.size(); i++)
		{
			if (str[i] != now_pattern[search_ind])
				break;

			search_ind++;
			if (search_ind == now_pattern.size())
			{
				multiple++;
				search_ind = 0;
			}
		}
		s.push_back(now_char);
		a.push_back(multiple);
		procceed += mymultiple(now_pattern, multiple);
		ind = procceed.size();
	}

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}