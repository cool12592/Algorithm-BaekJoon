#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int a;
	cin >> a;
	vector<int> vec(a);
    vector<int> temp_sol;
	int start, end, mid;
    temp_sol.push_back(vec[0]);
    
	for (int i = 0; i < a; i++)
	{
		cin >> vec[i];
        
        if (temp_sol[temp_sol.size() - 1] < vec[i])
		{
			temp_sol.push_back(vec[i]);
			
		}
		else
		{
			auto iter=lower_bound(temp_sol.begin(),temp_sol.end(),vec[i]);
			temp_sol[iter-temp_sol.begin()] = vec[i];
		}

	}








	cout << temp_sol.size()-1 << endl;


	return 0;
}