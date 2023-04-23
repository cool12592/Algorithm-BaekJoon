#include<iostream>
#include <vector>

using namespace std;

static int n, te, p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,num;
	cin >> n;

	string str;
	
	int size1=0, size2=0, size3=0, size4=0, size5=0, size6=0;

	for (int i = 0; i < n; i++)
	{
		cin >> str >> num;
		if (str == "II")
		{
			size1 += num;
		}
		if (str == "UU")
		{
			size2 += num;
		}
		if (str == "NN")
		{
			size3 += num;
		}
		if (str == "IU" || str == "UI")
		{
			size4 += num;
		}
		if (str == "IN" || str == "NI")
		{
			size5 += num;
		}
		if (str == "UN" || str == "NU")
		{
			size6 += num;
		}
	}

	
	bool a = size4 && size5;
	bool b = size4 && size6;
	bool c = size5 && size6;
	if (a || b || c)
	{
		cout << size1 + size2 + size3 + size4 + size5 + size6;
	}
	else if (size4 > 0)
	{
		cout << max(size4 + size1 + size2, size3);
	}
	else if (size5 > 0)
	{
		cout << max(size5 + size1 + size3, size2);
	}
	else if (size6 > 0)
	{
		cout << max(size6 + size2 + size3, size1);
	}
	else
	{
		cout << max(size1, max(size2, size3));
	}
	return 0;
}