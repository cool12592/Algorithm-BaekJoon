

#include <vector>

#include<iostream>

#include<algorithm>

using namespace std;
#define inf 987654321
int main() {
    int answer = 0;
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    vector<int> item(n+1, 0);
    for (int i = 1; i <= n; i++)
        scanf("%d", &item[i]);

    vector<vector<int>> dist(n+1,vector<int>(n+1, inf));
    int a, b, c;
    for (int i = 0; i < r; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    //하나씩 모든경로 최소비용구하고
    // 그중 m값 까지 인것만 체크해서 아이템 수 구하고
    //젤큰 아이템수 가진 노드 =>정답
    for (int i = 1; i <= n; i++) //경유지
    {
        for (int j = 1; j <= n; j++) //출발지
        {
            for (int k = 1; k <= n; k++) //목적지
            {
                dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
            }
        }
    }

    
    for (int i = 1; i <= n; i++)
    {
        int can_find_item = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] <= m)
            {
                can_find_item += item[j];
                answer = max(answer, can_find_item);
            }
        }
    }
    cout << answer;
    return 0;
}