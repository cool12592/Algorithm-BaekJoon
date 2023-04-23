#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;


int main()
{
	int n;
	scanf("%d", &n);

	vector<long long> vec(n, 0);


	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &vec[i]);
	}

	sort(vec.begin(), vec.end());

	int j, k;
	long long min_dif = 3000000001;
	vector<int> ans(3,0);
	bool end = false;

	for (int i = 0; i <= n-3; i++)
	{
		j = i+1;
		k = n - 1;
		long long dif;

	

		while (j < k)
		{
			dif = vec[i] + vec[j] + vec[k];
			if (min_dif > llabs(dif))
			{
				min_dif = llabs(dif);
				ans[0] = vec[i];
				ans[1] = vec[j];
				ans[2] = vec[k];

			}
			if (dif == 0)
			{
				end = true;
				break;
			}

			if (dif > 0)
				k--;
			else if (dif < 0)
				j++;


		}
		if (end)
			break;
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];
	//약7시 19분
	return 0;
}
