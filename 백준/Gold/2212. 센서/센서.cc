#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
using namespace std;




int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>vec(n);
	if (n <= k)
	{
		cout << 0; return 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}
	vector<int>dif;
	sort(vec.begin(), vec.end());
	for (int i = 1; i < n; i++)
	{
		dif.push_back(vec[i] - vec[i - 1]);
	}
	sort(dif.begin(), dif.end(),greater<int>());
	int answer = 0;
	for (int i = k-1; i < dif.size(); i++)
	{
		answer += dif[i];
	}
	cout << answer;
	return 0;
}