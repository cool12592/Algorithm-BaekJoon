#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#include<map>
#include<set>
#include<list>

#define inf 987654321
using namespace std;
int dy[] = { 0,0,1 };
int dx[] = { 1,-1,0 };
int n, m;
vector<vector<int>> vec;
vector<vector<vector<int>>> dp;


struct info {
    int y, x;
};

int answer = 0;

int dfs(info now, int pre_dir)
{

    if (now.y == n - 1 && now.x == m - 1)
    {
        return vec[n - 1][m - 1];
    }

    if (dp[now.y][now.x][pre_dir] != -inf)
        return dp[now.y][now.x][pre_dir];


    for (int i = 0; i < 3; i++)
    {
        int ny = now.y + dy[i];
        int nx = now.x + dx[i];
        if (ny >= n || nx >= m || ny < 0 || nx < 0)
            continue;

        if (pre_dir == 0 && i == 1) continue;
        if (pre_dir == 1 && i == 0) continue;

        int temp = dfs({ ny,nx }, i) + vec[now.y][now.x];

        dp[now.y][now.x][pre_dir] = max(dp[now.y][now.x][pre_dir], temp);



    }


    return dp[now.y][now.x][pre_dir];

}

int main()
{

    cin >> n >> m;
    vec.resize(n, vector<int>(m));
    dp.resize(n, vector<vector<int>>(m,vector<int>(3, -inf)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &vec[i][j]);
        }
    }





    cout << dfs({ 0,0 }, 0);

    return 0;
}