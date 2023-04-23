#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#include<stack>
#define inf 987654321

using namespace std;

vector<vector<int>>adj;
int dfs(int node)
{
    vector<int>vec;
    for (int i = 0; i < adj[node].size(); i++)
        vec.push_back(dfs(adj[node][i]));

    sort(vec.begin(), vec.end(), greater<int>());

    int res = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        res = max(res, vec[i] + i + 1);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n);
    int a;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == -1) continue;
        adj[a].push_back(i);
    }
    cout << dfs(0);

    return 0;
}