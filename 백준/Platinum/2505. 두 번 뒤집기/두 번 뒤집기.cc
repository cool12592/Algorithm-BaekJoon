#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<string>
using namespace std;


int main()
{

	int n;
	cin >> n;
	vector<int> vec(n + 1, 0);
	vector<int> originvec(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}
	originvec = vec;
	int cnt = 0; 
	pair<int, int> a1 = { 1,1 }, b1 = { 1,1 };
	for (int i = 1; i <= n; i++)
	{
		if (vec[i] != i)
		{
			cnt++;
			if (cnt > 2)
				break;
			stack<int> st;
			int targetpos;
			for (int j = 1; j <= n; j++)
				if (vec[j] == i)
					targetpos = j;
			for (int j = i; j <= targetpos; j++)
			{
				st.push(vec[j]);
			}
			int j = i;
			while (st.size())
			{
				vec[j] = st.top(); 
				st.pop();
				j++;
			}

			if (cnt == 1)
			{
				a1 = { i,targetpos };
			}
			else
			{
				b1 = { i,targetpos };
			}
		}
	}

	if (cnt > 2)
	{
		cnt = 3;
		vec = originvec;
		for (int i = n; i >= 1; i--)
		{
			if (vec[i] != i)
			{
				cnt++;
				if (cnt > 5)
					break;
				stack<int> st;
				int targetpos;
				for (int j = 1; j <= n; j++)
					if (vec[j] == i)
						targetpos = j;
	
				for (int j = i; j >= targetpos; j--)
				{
					st.push(vec[j]);
				}
				int j = i;
				while (st.size())
				{
					vec[j] = st.top();
					st.pop();
					j--;
				}

				if (cnt == 4)
				{
					a1 = { targetpos,i };
				}
				else
				{
					b1 = { targetpos,i };
				}
			}
		}
	}

	cout << a1.first << " " << a1.second<<endl;
	cout << b1.first << " " << b1.second << endl;

	return 0;
}