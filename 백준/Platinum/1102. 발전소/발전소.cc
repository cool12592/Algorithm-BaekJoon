#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;
int n;
int dp[1 << 16]; //a턴에 b를 고쳤을때 최소비용

int arr[16][16];
int p;

int dfs(int stat, int remain_p)
{
    if (dp[stat] != -1)
        return dp[stat];



    if (remain_p == 0) //고칠애없음
        return 0;



    int res = inf;
    for (int i = 0; i < n; i++)
    {
        if ((stat & (1 << i)) != 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if ((stat & (1 << j)) != 0) continue;

                res = min(res, dfs((stat | (1<<j)), remain_p - 1)+ arr[i][j]);
            }
        }
    }
   




    dp[stat] = res;
    return res;


}

int main()
{
    memset(dp, -1, sizeof dp);
    memset(arr, 0, sizeof arr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);


        }
    }
    string str;
    cin >> str;
    int num = 0;
    int stat = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'Y')
        {
            stat = (stat | (1 << i));
            num++;
        }
    }

    cin >> p;
    //예외처리
    if (num == 0)
    {
        if (p == 0)
        {
            cout << 0;
            return 0;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }
    else if (num >= p)
    {
        cout << 0;
        return 0;
    }




    p = p - num;//고쳐야되는애


    int res = inf;
    for (int i = 0; i < n; i++)
    {
        if ((stat & (1 << i)) != 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if ((stat & (1 << j)) != 0) continue;

                res = min(res, dfs((stat | (1 << j)), p - 1)+arr[i][j]);
            }
        }
    }


    cout << res;




    return 0;
}