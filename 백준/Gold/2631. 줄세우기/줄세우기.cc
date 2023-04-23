#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>



using namespace std;
int n;
vector<int> vec;
vector<int> lis;






int main()
{

	cin >> n;
	vec.resize(n);


	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
		
	}
	lis.push_back(vec[0]);
	for (int i = 1; i < n; i++)
	{
		if (lis[lis.size() - 1] < vec[i])
			lis.push_back(vec[i]);
		else
			lis[lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin()] = vec[i];

	}
	cout << vec.size() - lis.size();

	return 0;
}