#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>

#define inf 987654321
using namespace std;



int main()
{
    int n;
    cin >> n;
    int cost[21][21];
    int edge[21][21];
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            edge[i][j] = 1; //이 경로 유효하다
        }
    }



    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j || j == k || i == k) //어떤것도 같아선안됨
                    continue;
                if (cost[i][j] > cost[i][k] + cost[k][j]) //이러면 잘못된거(최솟값이라고 준애가 최솟값이아니다?!)
                {
                    cout << -1;
                    return 0;
                }
                //예를들어 1->3 == 1->2 + 2->3 이면 1->3바로가는 엣지는 지움(돌아가는게 최단이니까)
                else if(cost[i][j] == cost[i][k] + cost[k][j]) //돌아서가는게 젤 짧은거였다면
                {
                    edge[i][j] = 0; //바로가는 경로는 지운다
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (edge[i][j] == 1)
                sum += cost[i][j];
        }
    }
    cout << sum/2; //양쪽으로 더했기때문에 2로나눔 1->2더하고 2->1더해서
   
    return 0;
}