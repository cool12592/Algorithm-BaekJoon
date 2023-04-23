#include <iostream>
#include <string>
#include<vector>
#include<memory.h>
#include<map>
#include<set>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> pos(n+1);
	vector<bool> visit(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
		pos[vec[i]] = i;
	}

	vector<set<int>> group_vec;
	
	for (int i = 1; i <= n; i++)
	{
		int now = i;
		if (visit[now])
			continue;

		int now_pos = pos[now];


		int pastGroupMax = 0;
		if(group_vec.size())
			pastGroupMax = *group_vec.back().rbegin();
		
		if (now < pastGroupMax)
		{
			for (int k = now_pos; k >= 0; k--)
			{
				int num = vec[k];
				if (visit[num])
					break;
				visit[num] = 1;
				group_vec.back().insert(num);
			}
		}
		else
		{
			set<int> myset;
			for (int k = now_pos; k >= 0; k--)
			{
				int num = vec[k];
				if (visit[num])
					break;
				visit[num] = 1;
				myset.insert(num);
			}
			group_vec.push_back(myset);
		}
	}

	printf("%d\n", group_vec.size());
	for (auto myset : group_vec)
	{
		printf("%d ", myset.size());
		for (auto num : myset)
		{
			printf("%d ", num);
		}
		printf("\n");
	}

}