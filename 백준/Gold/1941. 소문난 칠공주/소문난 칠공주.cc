#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#define inf 987654321
//6시 20분 시작 읽고 풀이 10분
using namespace std;

struct info {
    int y, x;

};

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

vector<string>vec;

int combi_visit[26];


int check(vector<int>& temp)
{
    int s_count = 0;
  
    for (int i = 0; i < 7; i++)
    {
        if (vec[temp[i] / 5][temp[i] % 5] == 'S')
            s_count++;
    }
    if (s_count < 4) 
        return 0;
   
    vector<vector<pair<int, int>>> visit(5, vector<pair<int, int>>(5));
   
    for (int i = 0; i < 7; i++)
       visit[temp[i] / 5][temp[i] % 5] = { 0,1 };
        

    queue<info> q;

    q.push({ temp[0] / 5,temp[0] % 5 });
    visit[temp[0] / 5][temp[0] % 5] = { 1,1 };
    int count = 1;
    while (q.size() > 0)
    {
        info now = q.front();
        q.pop();


        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            if (visit[ny][nx].first == 1) continue;
            if (visit[ny][nx].second != 1) continue;

            visit[ny][nx].first = 1;
            count++;
            q.push({ ny,nx });
            if (count == 7) 
                return 1;
        }
    }
    
    return 0;

}


int dfs(int cnt,int ind)
{
    if (cnt == 7)
    {
        vector<int> temp;
        for (int i = 0; i <= 24; i++)
        {
            if (combi_visit[i] == 1)
              temp.push_back(i);

               
        }



        return  check(temp);
    }
    int res = 0;
    for (int i = ind; i <= 24; i++)//콤비네이션의 결과는 조합과 다르게 중복x라서 오름차순으로만 뽑음됨(즉 나 이후부터로보면됨)
    {
        if (combi_visit[i] == 0)
        {
            combi_visit[i] = 1;
           res+= dfs(cnt + 1, i);
           combi_visit[i] = 0;

        }
     
    }
    
    return res;
}


//1시10분
int main()
{
    string temp;
    for (int i = 0; i < 5; i++)
    {
        
            cin >> temp;
            vec.push_back(temp);
        
    }

    memset(combi_visit, 0, sizeof combi_visit);

    cout<<dfs(0, 0);

  
    return 0;
}