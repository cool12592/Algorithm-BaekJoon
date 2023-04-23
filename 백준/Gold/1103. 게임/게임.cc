#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;

int visit[50][50];
vector<vector<int>>dp(50, vector<int>(50, -2));
int n, m;
int arr[50][50];
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int dfs(int y, int x)
{
    

   
    
   
    if (y >= n || x >= m || y < 0 || x < 0)
        return 0;

    if (arr[y][x] == -1)//구멍
        return 0;

    if (visit[y][x] == 1) //싸이클발생
        return -1;
    
    if (dp[y][x] != -2)
        return dp[y][x];
    
    visit[y][x] = 1;

    int res = 0;
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
       temp = dfs(y + dy[i] * arr[y][x], x + dx[i] * arr[y][x]);
       if (temp == -1) //싸이클있었나
       {
           dp[y][x] = -1;
           return -1;

       }
       temp += 1;//걔가간cnt + 내가걔한테간cnt
       res = max(res, temp);
    }
    visit[y][x] = 0;
    dp[y][x] = res;
    return res;
    

}
int main()
{
    memset(visit, 0, sizeof visit);
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++)
    {
      
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'H')
                arr[i][j] = -1;
            else
                arr[i][j] = str[j]-'0';
        }
        
    }
    cout<<dfs(0, 0);
    return 0;
} 