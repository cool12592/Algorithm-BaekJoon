#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int sum = 0;
		if (a % 2 == 0)
			sum++;
		if (b % 2 == 0)
			sum++;
		if (c % 2 == 0)
			sum++;
		
		if (sum >= 2)
			printf("R\n");
		else
			printf("B\n");

	}

	return 0;
}