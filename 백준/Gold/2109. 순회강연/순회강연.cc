#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;
int parent[10001];
int find(int a)
{
    if (parent[a] == a) return a;

    return parent[a] = find(parent[a]);
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
int main()
{
    priority_queue<pair<int, int>>pq;
    int k;
    cin >> k;
    int a, b;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &a, &b);
        pq.push({ a,b });
    }
    for (int i = 0; i <= 10000; i++)
        parent[i] = i;
    int answer = 0;
    while (pq.size() > 0)
    {
        int day = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (find(day) == 0)
            continue;

        answer += cost;
        unite(day, find(day) - 1);


    }
    cout << answer;
    return 0;
}