#include <iostream>
#include <string>
#include<vector>
#include<memory.h>
#include<map>
#include<set>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int>vec(9);
	int maxindex=0;
	for (int i = 1; i <= 8; i++)
	{
		cin >> vec[i];

		if (vec[i] > vec[maxindex])
			maxindex = i;
	}
    if(n*m==2)
    {
        cout << "ChongChong";
    }
    else
    {
        cout << "GomGom";
    }
	
	return 0;
}