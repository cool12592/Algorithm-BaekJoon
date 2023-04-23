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
    char c;
};

int main() {
   

    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    {

        vector<vector<int>> vec2(n, vector<int>(n));
     
        int groupNumber = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vec2[i][j] == 0)
                {

                    groupNumber++;
                    vec2[i][j] = groupNumber;
                    queue<info> q;
                    q.push({ i,j,vec[i][j] });

                    while (q.size() > 0)
                    {
                        info now = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int ny = now.y + dy[k];
                            int nx = now.x + dx[k];
                            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                            if (vec[i][j] == vec[ny][nx] && vec2[ny][nx] != groupNumber)
                            {
                                vec2[ny][nx] = groupNumber;
                                q.push({ ny,nx,vec[ny][nx] });
                            }
                        }


                    }

                }
            }
        }
        cout << groupNumber << " ";
    }

    {
       
        vector<vector<int>> vec2(n, vector<int>(n));
        
        int groupNumber = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vec2[i][j] == 0)
                {

                    groupNumber++;
                    vec2[i][j] = groupNumber;
                    queue<info> q;
                    q.push({ i,j,vec[i][j] });

                    while (q.size() > 0)
                    {
                        info now = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int ny = now.y + dy[k];
                            int nx = now.x + dx[k];
                            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

                            if (vec[i][j] == 'B')
                            {
                                if (vec[i][j] == vec[ny][nx] && vec2[ny][nx] != groupNumber)
                                {
                                    vec2[ny][nx] = groupNumber;
                                    q.push({ ny,nx,vec[ny][nx] });
                                }
                            }
                            else
                            {
                                if ((vec[ny][nx]=='R'|| vec[ny][nx] == 'G')  && vec2[ny][nx] != groupNumber)
                                {
                                    vec2[ny][nx] = groupNumber;
                                    q.push({ ny,nx,vec[ny][nx] });
                                }
                            }
                        }


                    }

                }
            }
        }
        cout << groupNumber << " ";
    }
    return 0;
}
