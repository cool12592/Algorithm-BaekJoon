#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>

using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;
    int answer = 0;
    vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a][b] = 1;
        vec[b][a] = -1;
	}

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (vec[i][k] + vec[k][j] == 2)
                    vec[i][j] = 1;
                else if (vec[i][k] + vec[k][j] == -2)
                    vec[i][j] = -1;


            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 1;
        for (int j = 1; j <= n; j++)
        {
            if (vec[i][j] != 0)
                cnt++;
        }
        printf("%d\n", n - cnt);
     
    }


	return 0;
}