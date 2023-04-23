#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vec[i]);
           
        }
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
        vector<int>indgree(n + 1,0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                adj[vec[i]][vec[j]] = 1;
                indgree[vec[j]]++;
           }

        }
        int k;
        cin >> k;
        int a, b;
        bool finish = false;;
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &a, &b);
            if (adj[a][b] == 1)
            {
                adj[a][b] = 0;
                adj[b][a] = 1;
                indgree[b]--;
                indgree[a]++;
                
            }
            else
            {
                adj[a][b] = 1;
                adj[b][a] = 0;
                indgree[b]++;
                indgree[a]--;
            }
        }
     

        queue<int> q;
        vector<int>answer;
        int finish_node=0;

        for (int i = 1; i <= n; i++)
        {
            if (indgree[i] == 0)
            {
                q.push(i);
            }
        }
      

        while (q.size() > 0)
        {
            
            if (q.size() >= 2)
            {
               
                finish = true;
                break;

            }


            int now = q.front();
            q.pop();

            answer.push_back(now);
            finish_node++;
           
            for (int i = 1; i <= n; i++)
            {
                if (adj[now][i] == 1)
                {
                    adj[now][i] = 0;
                    indgree[i]--;
                    if (indgree[i] == 0)
                        q.push(i);
                }
            }
      
            
        }
        if (finish)
        {
            printf("?\n");
            continue;

        }

        if (finish_node != n)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }


        for (int i = 0; i < answer.size(); i++)
        {
           
                printf("%d ",answer[i]);
            
        }
        printf("\n");

    }



    return 0;
}