#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#include<map>
#define inf 987654321
using namespace std;



    
int main()
{
    int n,m;
    cin >> n>>m;
    vector<vector<pair<int,int>>>adj(n + 1);
    int a, b,c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b,&c);
        adj[a].push_back({ c,b });
    }
    int start, end_;
    scanf("%d %d", &start, &end_);

    priority_queue<pair<int, int>>pq;
    pq.push({ -0,start });
    vector<int> cost(n + 1,inf);
    vector<int> trace(n + 1);
    while (pq.size() > 0)
    {
        int now = pq.top().second;
        int now_cost = -pq.top().first;
        pq.pop();
        if (now_cost > cost[now])
            continue;
        if (now == end_)
            break;

        for (auto dest : adj[now])
        {
            int dest_node = dest.second;
            int dest_cost = dest.first;
            if (cost[dest_node] > now_cost + dest_cost)
            {
                cost[dest_node] = now_cost + dest_cost;
                pq.push({ -cost[dest_node] , dest_node });
                trace[dest_node] = now;
            }
        }

    }

   


  
    vector<int> trace_vec;
    int num = end_;
    while (num != start)
    {
        trace_vec.push_back(num);
        num = trace[num];
    }
    trace_vec.push_back(num);

    if (start == end_) cost[end_] = 0;
    printf("%d\n", cost[end_]);
    printf("%d\n", trace_vec.size());
    int len = trace_vec.size();

    for (int i = len-1; i >=0 ; i--)
    {
        printf("%d ", trace_vec[i]);
    }

    return 0;
}