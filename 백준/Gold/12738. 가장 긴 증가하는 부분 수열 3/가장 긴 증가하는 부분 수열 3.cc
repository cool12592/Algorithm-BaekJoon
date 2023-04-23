#include<iostream>
#include<vector>

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
	
	vector<int> lis;
	lis.push_back(vec[0]);
	
	for (int i = 1; i < n; i++)
	{

		if (lis[lis.size() - 1] < vec[i])
			lis.push_back(vec[i]);
		else
		{
			lis[lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin()] = vec[i];
		}
		//if (sol.size() < temp_sol.size())
		//	sol = temp_sol; //더 긴애 나오면 정답 갱신 
	}

	cout << lis.size() << endl;;
	//for (int i = 1; i < sol.size(); i++)
	//	cout << sol[i] << " ";
	return 0;
}