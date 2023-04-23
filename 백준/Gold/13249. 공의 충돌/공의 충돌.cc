#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() 
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}
	int t;
	cin >> t;

	sort(vec.begin(), vec.end());
	double ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		int now = vec[i];
		for (int j = i+1; j < n; j++)
		{
			int target = vec[j];
			if (target - t <= now + t)
				ans += 0.25;
		}
		
	}
	cout << ans;
	return 0;
}