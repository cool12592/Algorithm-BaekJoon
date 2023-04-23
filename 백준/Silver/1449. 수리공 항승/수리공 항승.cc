#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n,tap;
	cin >> n>>tap;
	int input;
	vector<int> vec;
	int sum = 0;
	int now = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		vec.push_back(input);
	
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > now)
		{
			sum++;
			now = vec[i] + tap - 1;
		}
	}
	cout << sum;
	return 0;
}