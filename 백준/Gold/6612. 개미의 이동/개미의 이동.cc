#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;



int main() 
{
	int len, n;
	while (cin >> len >> n)
	{
		vector<int> vecR;
		vector<int> vecL;
		vector<int> vec(n);

		for (int i = 0; i < n; i++)
		{
			int a;
			char c;
			scanf("%d %c", &a, &c);
			if (c == 'R')
			{
				vecR.push_back(a);
			}
			else
			{
				vecL.push_back(a);
			}
			vec[i] = a;
		}
		sort(vec.begin(), vec.end());
		sort(vecR.begin(), vecR.end());
		sort(vecL.begin(), vecL.end());
		int sizeR = vecR.size();
		int sizeL = vecL.size();

		int time1 = -1;
		int time2 = -1;
		int start1 = -1;
		int start2 = -1;

		if (sizeR != 0)
		{
			time1 = len - vecR[0];
			start1 = vec[n - sizeR];
		}
		if (sizeL != 0)
		{
			time2 = vecL[sizeL-1];
			start2 = vec[sizeL-1];
		}

		
		if (time1 == time2)
		{
			printf("The last ant will fall down in %d seconds - started at %d and %d.\n", time1, start2,start1);
		}
		else if (time1 > time2)
		{
			printf("The last ant will fall down in %d seconds - started at %d.\n",time1,start1);
		}
		else if (time1 < time2)
		{
			printf("The last ant will fall down in %d seconds - started at %d.\n", time2, start2);
		}

	}

}