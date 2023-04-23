#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(366,0);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a,&b);
		for (int i = a; i <= b; i++)
			vec[i]++;

	}
	
	int row = 0;
	int col = 0;
	int sol = 0;
	for (int i = 1; i <= 365; i++)
	{
		if (vec[i] == 0)
		{
			if (row != 0)
			{
				sol +=  row * col;
				row = 0;
				col = 0;
			}
		}
		else
		{
			row++;
			col = max(col, vec[i]);

		}
	}
	sol += row * col;
	cout << sol;
	return 0;
}