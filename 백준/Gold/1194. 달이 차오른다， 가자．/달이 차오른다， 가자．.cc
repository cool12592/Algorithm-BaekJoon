#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#include<map>
#include<set>
#include<list>

#define inf 987654321
using namespace std;

int N;
int n, m;
char arr[50][50];
int visit[50][50][1<<6+1];
struct pos {
    int y, x;
    int info;
    int count;
};
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
int finish = -1;


int main()
{
    cin >> n >> m;
    pos start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == '0')
            {
                start.y = i;
                start.x = j;
            }
        }
    }
    N = (1 << 6);
    start.info = N;
    start.count = 0;
    queue<pos>q;
    q.push(start);
    visit[start.y][start.x][q.front().info] = 1;
    while (q.size() > 0)
    {
        pos now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny >= n || nx >= m || ny < 0 || nx < 0)
                continue;
            
            if (visit[ny][nx][now.info] == 1) continue;

            if (arr[ny][nx] == '#') continue;

            else if (arr[ny][nx] == '1')
            {
                cout << now.count + 1;
                return 0;
            }
            else if (arr[ny][nx] == '.' || arr[ny][nx] == '0')
            {
                visit[ny][nx][now.info] = 1;
                q.push({ ny,nx,now.info,now.count + 1 });
            }
            else if ((int)arr[ny][nx] >= 97) //소문자 알파벳
            {

                //열쇠획듣
                visit[ny][nx][now.info | (1 << ((int)arr[ny][nx] - 97))]=1;
                q.push({ ny,nx,now.info | (1 << ((int)arr[ny][nx] - 97)),now.count + 1 });

            }
            else if ((int)arr[ny][nx] >= 65) //대문자 알파벳
            {

                if ((now.info & (1 << ((int)arr[ny][nx] - 65))) != 0)
                {
                    visit[ny][nx][now.info]=1;
                    q.push({ ny,nx,now.info,now.count + 1 });
                }


            }
        }

    }
    cout << -1;
    return 0;
}