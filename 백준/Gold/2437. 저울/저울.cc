#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int input;
	int sum=0;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		vec[i] = input;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		if (sum + 1 < vec[i]) //새로운 추가 기존추합보다 2이상크면안됨 (기존추합5 새추7 그럼 6못잼)
		{
			cout << sum + 1;
			return 0;
		}
		sum += vec[i];

	}
	cout << sum + 1;
	return 0;
}