
#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;



int main() {
 
    int n, m;
    cin >> n >> m;
    int num;
    vector<int> indegree(n + 1);
    vector<vector<int>> adj(n + 1);
    int new_,past_;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        for (int k = 0; k < num; k++)
        {     

            if(k==0)
                scanf("%d", &past_);
            else
            {
                scanf("%d", &new_);
                
                adj[past_].push_back(new_);
                indegree[new_]++;
                past_ = new_;

            }
            
        }
    }
    int count=0;//지워진수
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int>answer;

    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        answer.push_back(now);
        count++;
        
      
        for (int i = 0; i < adj[now].size(); i++)
        {
            indegree[adj[now][i]]--;
            if (indegree[adj[now][i]] == 0)
                q.push(adj[now][i]);
        }
        
    }

 

    if (count != n)
        cout << 0;
    else
    {
        for (int i = 0; i < answer.size(); i++)
            printf("%d\n", answer[i]);
    }
    

    return 0;
}