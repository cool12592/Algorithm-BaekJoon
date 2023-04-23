#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



int main() 
{
	string str;
	cin >> str;
	int left = 0;
	int right = str.size() - 1;
	int len = str.size();
	bool b = true;
	bool allequal = true;

	for (int i = 0; i < len-1; i++)
	{
		if (str[i] != str[i + 1])
		{
			allequal = false;
			break;
		}
	}

	if (allequal)
	{
		cout << -1;
		return 0;
	}

	while (left < right)
	{
		if (str[left] != str[right])
		{
			b = false;
			break;
		}
		left++;
		right--;
	}
	if (b == false)
	{
		cout << len;
	}
	else
	{
		cout << len - 1;

	}


	return 0;
}