#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



int main() 
{
	int n;
	cin >> n;
	vector<int> vec(n);
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
		sum += vec[i];
	}
	if (n == 1)
		cout << vec[0];
	else
	{
		double average = (sum / vec.size());
		sort(vec.begin(), vec.end());
		printf("%.6f", max(average, (double)vec[vec.size() - 2]));

	}

	return 0;
}