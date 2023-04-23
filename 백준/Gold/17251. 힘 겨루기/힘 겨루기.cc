#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<string>
#include<queue>
using namespace std;


int main()
{

	int n;
	cin >> n;
	vector<int> vec(n);
	int a=0, b=0;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i]);
	}

	vector<int> indexBigVec(n);
	int index_big = -1;
	for (int i = n-1; i >= 0; i--)
	{
		if (vec[i] > index_big)
		{
			index_big = vec[i];
		}
		indexBigVec[i] = index_big;
	}

	for (int i = 0; i < n - 1; i++)
	{
		pq.push(vec[i]);
		
		
		int leftBig = pq.top();
		int rightBig = indexBigVec[i+1];
		if (leftBig > rightBig)
			a++;
		else if (leftBig < rightBig)
			b++;
	}


	if (a > b)
		cout << "R";
	else if (a < b)
		cout << "B";
	else
		cout << "X";
	return 0;
}