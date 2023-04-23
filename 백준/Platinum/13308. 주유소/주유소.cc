//5시 30분
//개념이해하는데 1시간
//6시25분 코딩시작

#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int>node(n+1,0); //노드의 기름
    vector<vector<pair<int,int>>>dist(n+1); //목적지,비용
    for (int i = 1; i <= n; i++)
        scanf("%d", &node[i]);
    int s, e, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &s, &e, &c);
        dist[s].push_back({ e,c });
        dist[e].push_back({ s,c });
    }

    priority_queue<pair<int,pair<int,int>>> pq; //총비용 현재노드 현재최소기름비용
   // vector<vector<bool>> visit(n, vector<int>(2500, false));  //인덱스는 [현재노드][현재최소비용]
    bool visit[250][250] = { false, };//인덱스는 [현재노드][현재최소비용]

    pq.push({ 0,{1,node[1]} });
    while (pq.size() > 0)
    {
        int total = -pq.top().first;
        int now_node = pq.top().second.first;
        int min_oil_cost = pq.top().second.second;
        pq.pop();
        if (now_node == n)
        {
            cout << total;
            return 0;
        }
        if (visit[now_node][min_oil_cost])
            continue;
        visit[now_node][min_oil_cost] = true;
        for (auto next : dist[now_node]) //현재에서 갈수있는 목적지, 비용 리스트
        {
            int next_min_oil_cost = min(min_oil_cost, node[next.first]);//다음에 쓸 최소기름비용(pq에는이걸로넣음)
            int next_total = total + next.second * min_oil_cost;//총비용=> 현재 토탈+ 다음노드까지 거리*지금쓸수있는 최소기름비용
            pq.push({ -next_total,{next.first,next_min_oil_cost} });

        }
    }

    return 0;
}