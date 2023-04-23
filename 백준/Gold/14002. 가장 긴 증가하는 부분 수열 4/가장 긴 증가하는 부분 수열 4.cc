#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int a;
	cin >> a;
	vector<long long> vec(a);
	vector<long long> Lis;
	Lis.push_back(-1000000001);
	vector<int> index_save(a);
	int max_;
	for (int i = 0; i < a; i++)
	{
		cin >> vec[i];

		if (Lis[Lis.size() - 1] < vec[i])
		{
			Lis.push_back(vec[i]);
			index_save[i] = Lis.size()-1; //Lis안에서의 인덱스를 저장
			max_ = i;
		}
		else
		{
			auto iter = lower_bound(Lis.begin(), Lis.end(), vec[i]);
			Lis[iter - Lis.begin()] = vec[i];
			index_save[i] = iter - Lis.begin(); //Lis안에서의 인덱스를 저장
		}
	
	}


	cout << Lis.size() -1 << endl;
	int target= index_save[max_]; //타겟숫자 5
	vector<long long>sol(target);
	sol[target - 1] = vec[max_];
	target--;
	for (int i = max_ - 1; i >= 0; i--)
	{
		if (index_save[i] == target)
		{
			sol[target - 1] = vec[i];
			target--;
			if (target == 0)
				break;
		}
	}
	for (int i = 0; i < sol.size(); i++)
	{
		cout << sol[i] << " ";
	}
	return 0;
}