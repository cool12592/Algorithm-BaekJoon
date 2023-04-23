#include<iostream>
#include<vector>

using namespace std;



int main()
{
	int a;
	cin >> a;
	vector<int> vec(a);
	for (int i = 0; i < a; i++)
	{
		cin >> vec[i];
	}
	//vector<long long> sol;
	vector<int> temp_sol;
	int start, end,mid;
	temp_sol.push_back(-1000000001);
	for (int i = 0; i < vec.size(); i++)
	{
	
		if (temp_sol[temp_sol.size() - 1] < vec[i])
			temp_sol.push_back(vec[i]);
		else
		{
			start = 0;
			end = temp_sol.size() - 1;
			while (start < end)
			{
				mid = (start + end) / 2;
				if (temp_sol[mid] >= vec[i])
					end = mid;
				else
					start++;
			}
			temp_sol[end] = vec[i];
		}
		//if (sol.size() < temp_sol.size())
		//	sol = temp_sol; //더 긴애 나오면 정답 갱신 
	}

	cout << temp_sol.size() - 1 << endl;;
	//for (int i = 1; i < sol.size(); i++)
	//	cout << sol[i] << " ";
	return 0;
}