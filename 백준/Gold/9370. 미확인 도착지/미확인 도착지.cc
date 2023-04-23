#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#define inf 987654321
//4시15분구현시작(읽고풀이는 많아야 한 10분걸린듯? 5~10분)
using namespace std;


int main()
{
    int a, b, c, n, m, t, s, g, h, entire;
    cin >> entire;

    while (entire--)
    {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        vector<vector<pair<int, int>>>adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back({ b,c });
            adj[b].push_back({ a,c });
        }
        vector<int>dest_candi(t);
        for (int i = 0; i < t; i++)
        {
            scanf("%d", &dest_candi[i]);
        }
        sort(dest_candi.begin(), dest_candi.end());
        vector<vector<int>> trace(n + 1);
        vector<int> cost(n + 1, inf);
        priority_queue<pair<int, int>> pq;
        pq.push({ -0,s });
        cost[s] = 0;
        while (pq.size() > 0)
        {
            int now = pq.top().second;
            int now_cost = -pq.top().first;
            pq.pop();
            if (now_cost > cost[now])
                continue;

            for (int i = 0; i < adj[now].size(); i++)
            {
                int dest = adj[now][i].first;
                int next_cost = adj[now][i].second;
                if (cost[dest] > now_cost + next_cost)
                {
                    trace[dest].clear();
                    trace[dest].push_back(now);//now에서 dest까지 가는게 최단이다
                    cost[dest] = now_cost + next_cost;
                    pq.push({ -cost[dest], dest });
                }
                else if (cost[dest] == now_cost + next_cost)
                {
                    trace[dest].push_back(now);
                }
            }
        }
        for (int i = 0; i < t; i++)
        {
            queue<int>q;
            vector<int>visit(n + 1);
        
            int dest_candi_val = dest_candi[i];
            q.push(dest_candi_val);
            bool fast_end = false;
            while (q.size()>0)
            {
                int now = q.front();
                q.pop();

                for (int i = 0; i < trace[now].size(); i++)
                {
                    if (visit[trace[now][i]] == 0)
                    {
                        visit[trace[now][i]] = 1;
                        q.push(trace[now][i]);
                    }
                    if (now == g && trace[now][i] == h)
                    {
                        printf("%d ", dest_candi_val);
                        fast_end = true;
                        break;
                    }
                    else if (now == h && trace[now][i] == g)
                    {
                        printf("%d ", dest_candi_val);
                        fast_end = true;
                        break;
                    }
                }
                if (fast_end)
                    break;
            }

           
          

        }
        printf("\n");
    }


    return 0;
}