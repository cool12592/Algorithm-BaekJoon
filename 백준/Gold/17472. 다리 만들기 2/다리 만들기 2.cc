#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>

#define inf 987654321
using namespace std;
vector<vector<int>>vec;


struct pos {
    int y, x;
};

struct edge {
    int weight, island1, island2;
};

bool cmp(edge a, edge b)
{
    return a.weight < b.weight;
}

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int parent[10];

int myfind(int n)
{
    if (parent[n] == n) return n;
    else
        parent[n] = myfind(parent[n]);
    return parent[n];
}

void unite(int a, int b)
{
     a = myfind(a);
     b = myfind(b);

    parent[a] = b;
}


int main()
{
    int n, m,num;
    
    cin >> n >> m;
    vec.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &vec[i][j]);

        }
    }
    int island_num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 1)
            {
                island_num++;
                queue<pos> q;
                q.push({ i,j });
                vec[i][j] = island_num;
                while (q.size() > 0)
                {
                    pos now = q.front();
                    q.pop();
                    int ny;
                    int nx;
                    for (int i = 0; i < 4; i++)
                    {
                        ny = now.y + dy[i];
                        nx = now.x + dx[i];
                        if (ny >= n || nx >= m || ny < 0 || nx < 0)
                            continue;
                        if (vec[ny][nx] == 1)
                        {
                            vec[ny][nx] = island_num;
                            q.push({ ny,nx });
                        }
                    }
                }
            }
        }
    }
    vector<edge> ed;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 0)//바다면
                continue;
         
            //위로
            int up = 0;
            for (int k = i + 1; k < n; k++)
            {
                if (vec[k][j] == vec[i][j])//같은섬이면
                    break;
                else if (vec[k][j] == 0) //바다면 다리개수증가
                    up++;
                else if(up<=1)//다른섬인데 다리길이가 1이하면
                {

                    break;
                }
                else //위에조건 다 아닌 즉 다른섬인데 다리길이2이상이면
                {
                  
                    ed.push_back({ up, vec[i][j],vec[k][j] });
                    break;
                }

            }

            //오른쪽
            int right = 0;
            for (int k = j + 1; k < m; k++)
            {
                if (vec[i][k] == vec[i][j])//같은섬이면
                    break;
                else if (vec[i][k] == 0) //바다면 다리개수증가
                    right++;
                else if (right <= 1)//다른섬인데 다리길이가 1이하면
                {

                    break;
                }
                else //위에조건 다 아닌 즉 다른섬인데 다리길이2이상이면
                {

                  

                    ed.push_back({ right, vec[i][j],vec[i][k] });
                    break;
                }

            }

            //아래로
            int down = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                if (vec[k][j] == vec[i][j])//같은섬이면
                    break;
                else if (vec[k][j] == 0) //바다면 다리개수증가
                    down++;
                else if (down <= 1)//다른섬인데 다리길이가 1이하면
                {

                    break;
                }
                else //위에조건 다 아닌 즉 다른섬인데 다리길이2이상이면
                {
                    ed.push_back({ down, vec[i][j],vec[k][j] });
                    break;
                }

            }

            //왼쪽
            int left = 0;
            for (int k = j - 1; k >=0; k--)
            {
                if (vec[i][k] == vec[i][j])//같은섬이면
                    break;
                else if (vec[i][k] == 0) //바다면 다리개수증가
                    left++;
                else if (left <= 1)//다른섬인데 다리길이가 1이하면
                {

                    break;
                }
                else //위에조건 다 아닌 즉 다른섬인데 다리길이2이상이면
                {
                    ed.push_back({ left, vec[i][j],vec[i][k] });
                    break;
                }

            }

        }
    }

    sort(ed.begin(), ed.end(),cmp);
    int answer = 0;
    for (int i = 2; i < 10; i++)
        parent[i] = i;

    int connect = 0;
    for (int i = 0; i < ed.size(); i++)
    {
        if (myfind(ed[i].island1) != myfind(ed[i].island2))
        {
            unite(ed[i].island1, ed[i].island2);
            answer += ed[i].weight;
            connect++;
            if (connect == island_num - 2)
                break;
        }
    }
    if (connect != island_num - 2)
        cout << -1;
    else
    cout << answer;
    return 0;
}