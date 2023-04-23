#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define inf 2000000001
//6시 51분
int main()
{  
    int a, b;
    cin >> a >> b;
    vector<vector<int>> vec(b,vector<int>(3, 0));
    vector<vector<pair<int,int>>> adj(a + 1);
    for (int i = 0; i < b; i++)
    {
        scanf("%d %d %d", &vec[i][0], &vec[i][1], &vec[i][2]);
        adj[vec[i][0]].push_back({ -vec[i][2],vec[i][1] });
        adj[vec[i][1]].push_back({ -vec[i][2],vec[i][0] });
    }
    priority_queue<pair<int, int>> pq;

    pq.push({ -0, 1 });//출발
    int sum = 0;
    vector<int>visit(a + 1, 0);
    int cost = 0;
    while (pq.size())
    {
        cost= -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (visit[node] == 1)
            continue;

        visit[node] = 1;
        sum += cost;
        for (auto adj_ : adj[node])
        {
            pq.push(adj_);
        }

    }

    cout << sum << endl;

    return 0;
}
