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

    int n, m;
    cin >> n >> m;
    int a,b,c;
    vector<vector<pair<int,int>>>adj(n+1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d  %d %d", &a, &b, &c);
        adj[a].push_back({ b,c });


    }

    bool cycle = false;
    vector<long long>cost(n + 1,inf);
    cost[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < adj[j].size(); k++)
            {
                int dest = adj[j][k].first;
                int dest_cost = adj[j][k].second;
                if (cost[j] != inf && cost[dest] > cost[j] + dest_cost)
                {
                    cost[dest] = cost[j] + dest_cost;
                    if (i == n)
                        cycle = true;
                }
            }
        }
    }
    
    if (cycle)
        cout << -1;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if(cost[i]==inf)
                cost[i]=-1;
            printf("%d\n", cost[i]);
        }
    }

    return 0;
}