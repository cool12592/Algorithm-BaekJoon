#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#define inf 987654321
//6시 20분 시작 읽고 풀이 10분
using namespace std;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };


int main()
{

    int entire;
    cin >> entire;
    while (entire--)
    {
        int keys[26] = { 0, };
        int n, m;
        cin >> n >> m;
        n += 2;
        m += 2;
        vector<string> vec(n);

      
            for (int i = 0; i < m; i++)
            {
                vec[0] += '.';
                vec[n-1] += '.';
            }
        

        for (int i = 1; i < n-1; i++)
        {
            vec[i].push_back('.');
            string str;
            cin >> str;
            vec[i] += str;
            vec[i] += '.';
        }
        string mykey;
        cin >> mykey;
        if (mykey != "0")
        {
            for (int i = 0; i < mykey.size(); i++)
            {
                keys[(int)mykey[i] - 97] = 1;
            }
        }
        vector<vector<int>> visit(n, vector<int>(m));
        vector<queue<pair<int, int>>> lock(26);
        int answer = 0;
        queue<pair<int,int>> q;
        q.push({ 0,0 });
        while (q.size() > 0)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || vec[ny][nx]=='*' ||visit[ny][nx]==1) continue;

                if (vec[ny][nx] == '.')
                {
                    visit[ny][nx] = 1;
                    q.push({ ny,nx }); 

                }
                else  if (vec[ny][nx] == '$')
                {
                    vec[ny][nx] = '.';
                    visit[ny][nx] = 1;
                    q.push({ ny,nx });
                    answer++;
                }
             
                else if ((int)vec[ny][nx] >= 65 && (int)vec[ny][nx] <97)
                {
                    if (keys[(int)vec[ny][nx] - 65] == 0)
                        lock[(int)vec[ny][nx] - 65].push({ ny,nx });
                    else
                    {
                        vec[ny][nx] = '.';
                        visit[ny][nx] = 1;
                        q.push({ ny,nx });
                    }

                }
                else //소문자 열쇠
                {
                  
                    
                       
                        if (keys[(int)vec[ny][nx] - 97] == 0)
                        {
                            int num = (int)vec[ny][nx] - 97;
                            keys[num] = 1;
                            while (lock[num].size() > 0)
                            {
                                q.push(lock[num].front());
                                visit[lock[num].front().first][lock[num].front().second] = 1;
                                lock[num].pop();
                            }
                        }

                        vec[ny][nx] = '.';
                        visit[ny][nx] = 1;
                        q.push({ ny,nx });
                    
                }
                
            }
        }
        printf("%d\n",answer);
    }

    
    return 0;
}