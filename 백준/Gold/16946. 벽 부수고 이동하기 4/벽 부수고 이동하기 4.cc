#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

struct info {
    int y, x;
  
};

int main() {
   

    int n,m;
    cin >> n>>m;
    vector<string> vec(n);
    vector<vector<int>> visit(n, vector<int>(m));
    int movenumber[1000001] = {0,};
    

    for (int i = 0; i < n; i++)
    {
        //for (int j = 0; j < m; j++)
        //{
        cin >> vec[i];
      // }
    }

    int groupNumber = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j]=='0'&&visit[i][j] ==0 )
            {
             
                groupNumber++;
                visit[i][j] = groupNumber;
                movenumber[groupNumber]=0;
                queue<info> q;
                q.push({ i,j });

                while (q.size() > 0)
                {
                    info now = q.front();
                    q.pop();
                    movenumber[groupNumber]++;
                  
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = now.y + dy[k];
                        int nx = now.x + dx[k];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                        if (vec[ny][nx]=='0' && visit[ny][nx] != groupNumber)
                        {
                            visit[ny][nx] = groupNumber;
                            q.push({ ny,nx });
                        }
                    }


                }
         
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == '1')
            {
                int num = 0;
                vector<int> v;
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if (find(v.begin(), v.end(), visit[ny][nx]) == v.end())
                    {
                        num += movenumber[visit[ny][nx]];
                        v.push_back(visit[ny][nx]);
                    }
                }
                num++;
                vec[i][j] = (char)(num%10 +48) ;
            }
          
        }
  
    }
    for (int i = 0; i < n; i++)
    {
      
        cout << vec[i];
        
        printf("\n");
    }
  

        
    

    return 0;
}
