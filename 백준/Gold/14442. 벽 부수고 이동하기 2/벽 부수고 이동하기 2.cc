#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>

#define inf 987654321
using namespace std;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
struct info {
    int y, x;
    int remain;
    int count;
};

int main()
{
    int n,m,k;
    cin >> n>>m>>k;
    vector<string> vec(n);
    int visit[1000][1000][11] = { 0, };

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
         
    }

    queue<info> q;
    q.push({ 0,0,k,1 });
    visit[0][0][k] = 1;
    while (q.size() > 0)
    {
        info now = q.front();
        q.pop();
        if (now.y == n - 1 && now.x == m - 1)
        {
            cout << now.count;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (vec[ny][nx] == '1')
            {
                if (now.remain>0 && visit[ny][nx][now.remain-1] ==0)
                {
                    visit[ny][nx][now.remain-1] = 1;
                    q.push({ ny,nx,now.remain - 1,now.count + 1 });
                }
            }
            else
            {
                if (visit[ny][nx][now.remain]==0)
                {
                    visit[ny][nx][now.remain] = 1;
                    q.push({ ny,nx,now.remain,now.count + 1 });
                }
            }
        }

    }
    cout << -1;
    return 0;
}