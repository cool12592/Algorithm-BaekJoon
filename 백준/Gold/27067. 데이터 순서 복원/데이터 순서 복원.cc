#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
#include<map>
using namespace std;

//10시 47분시작 풀이 11시15분까지 (30분풀이ㄷㄷ)
//내가생각한 풀이법
//l1-2 2-3 1-3 행끼리 lcs로 최장공통숫자찾고
//이렇게 lcs로 만든 3행끼리 위상정렬로 순서찾으면 끝
//아 11시 47분 채점 54%에서 실패.... 1시간걸렸지만 틀렸군 머가틀렸지

bool visit[30001][3001] = { false, };
vector<int> indegree;
vector<vector<int>> adj;
vector<int> vec1, vec2, vec3;
vector<int> pos1, pos2, pos3;
int n;
void myfunc(vector<int>& pos, vector<int>vec)
{
    for (int i = 0; i < n; i++)
    {
        int now = vec[i];
        for (int j = i+1; j < n; j++)
        {
            int dest = vec[j];
            if (pos[now] < pos[dest])
            {
                if (visit[now][dest] == false)
                {   
                    visit[now][dest] = true;
                    indegree[dest]++;
                    adj[now].push_back(dest);
                }
            }
        }
    }
}

int main() {

    cin >> n;

    indegree.resize(n + 1, 0);
    adj.resize(n + 1, vector<int>(n + 1, 0));
    vec1.resize(n); vec2.resize(n); vec3.resize(n);
    pos1.resize(n+1); pos2.resize(n+1); pos3.resize(n+1);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec1[i]);
        pos1[vec1[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec2[i]);
        pos2[vec2[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec3[i]);
        pos3[vec3[i]] = i;
    }
    
   
    myfunc(pos1, vec2);
    myfunc(pos2, vec3);
    myfunc(pos3, vec1);

        
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    //위상 정렬
    vector<int> ans;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        ans.push_back(now);

        for (int dest : adj[now])
        {
            indegree[dest]--;
            if (indegree[dest] == 0)
                q.push(dest);
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}