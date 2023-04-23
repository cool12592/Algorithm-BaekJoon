#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#define inf 987654321
using namespace std;



int main()
{

    int t;
    cin >> t;
    for (int iiii = 0; iiii < t; iiii++)
    {
        int n, m, w;
        int a, b, c;
        scanf("%d %d %d", &n, &m, &w);
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, inf));
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (adj[a][b] > c)
            {
                adj[a][b] = c;
                adj[b][a] = c;
            }
        }
        for (int i = 0; i < w; i++) //웜홀
        {
            scanf("%d %d %d", &a, &b, &c);
            if (adj[a][b] > -c)
            {
                adj[a][b] = -c; //웜홀은 단방향
            }
        }

        string answer = "NO";

        vector<int> cost(n + 1, inf);
      //  cost[1] = 0;
        for (int i = 1; i <= n; i++)
        { 
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    
                    if (cost[k] > adj[j][k] + cost[j])
                    {
                        cost[k] = adj[j][k] + cost[j];
                        if (i == n)
                            answer = "YES";
                    }
                }
            }
        }
        cout << answer;
        printf("\n");
    }


    return 0;
}