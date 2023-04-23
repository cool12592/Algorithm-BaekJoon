#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;

int parent[1001];

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
    
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        pq.push({ b, a });
    }
    for (int i = 0; i <= 1000; i++)
        parent[i] = i;

    int answer = 0;
    while (pq.size() > 0)
    {
        pair<int,int> now = pq.top();
        pq.pop();
        if (find(now.second) == 0)
            continue;
        answer += now.first;
        unite(now.second, find(now.second) - 1);
        
    }
    cout << answer;
    return 0;
} 