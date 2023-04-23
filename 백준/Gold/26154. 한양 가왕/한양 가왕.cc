#include<iostream>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;
	vector<set<int>> vec(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec[i].insert(a);
		vec[i].insert(b);
	}

	for (int i = 0; i < m; i++)
	{
		if (i == n)
		{
			break;
		}

		vector<set<int>> temp(n);

		temp[0].insert(*vec[0].rbegin());
		temp[n - 1].insert(*vec[0].begin());

		for (int i = 1; i < n; i++)
		{
			temp[i-1].insert(*vec[i].rbegin());
			temp[i].insert(*vec[i].begin());
		}
		vec = temp;
		/*cout << endl;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			printf("%d %d\n", *vec[i].begin(), *vec[i].rbegin());
		}*/
		
		if (i == m - 1) //이미 다했으면 그냥 출력
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d %d\n", *vec[i].begin(), *vec[i].rbegin());
			}
			return 0;
		}
	}

	vector<set<int>> ans(n);
	for (int i = 0; i < n; i++)
	{
		int min_num = *vec[i].begin();
		int max_num = *vec[i].rbegin();

		int need_move_cnt = m - n; //이만큼더이동필요
		need_move_cnt = need_move_cnt % n;

		if (i == 0)
		{
			ans[i].insert(max_num);
			int dest = i - need_move_cnt;
			if (dest < 0)
				dest = n + dest;
			ans[dest].insert(min_num);
		}
		else
		{
			ans[i].insert(min_num);
			int dest = i - need_move_cnt;
			if (dest < 0)
				dest = n + dest;
			ans[dest].insert(max_num);
		}
		
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", *ans[i].begin(), *ans[i].rbegin());
	}
	return 0;
}