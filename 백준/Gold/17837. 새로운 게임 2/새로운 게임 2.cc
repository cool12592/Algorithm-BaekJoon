#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#define inf 987654321

using namespace std;
int n, k;
int arr[13][13] = { 0, };
int kvec[13][13][10] = { 0, };

struct info {

    int y, x;
    int dir;
};
info kpos[11];

pair<int, int> nextFunc(int dir)
{
    if(dir==1)
    {
        return { 0,1 };
    }
    if (dir == 2)
    {
        return { 0,-1 };
    }
    if (dir == 3)
    {
        return { -1,0 };
    }
    if (dir == 4)
    {
        return { 1,0 };
    }
}

int changeDir(int dir)
{
    if (dir == 1)
    {
        return 2;
    }
    if (dir == 2)
    {
        return 1;
    }
    if (dir == 3)
    {
        return 4;
    }
    if (dir == 4)
    {
        return 3;
    }
}

bool reverse_move(int ny, int nx)
{
    if (ny <= 0 || nx <= 0 || ny >= n+1 || nx >= n+1 || arr[ny][nx] == 2)
    {
        return true;
    }
    return false;
}
bool endgame = false;
void mymove(int index,int ny, int nx)
{
    int y = kpos[index].y;
    int x = kpos[index].x;

    int nextind = 0;
    for (int k = 0; k < 10; k++)
    {
        if (kvec[ny][nx][k] == 0)
        {
            nextind=k; //다음에갈곳
            break;
        }
    }
    vector<int> vec;
    for (int i = 0; i < 10;i++)
    {
        if (kvec[y][x][i] == index)
        {
            for (int j = i; j < 10; j++)
            {
                if (kvec[y][x][j] == 0)
                    break;

                vec.push_back(j);//데려갈 애들


               
            }
            break;
        }
    }
    int len = vec.size();
    if (arr[ny][nx] == 0)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            int now_ind = kvec[y][x][vec[i]];

            kpos[now_ind].y = ny;
            kpos[now_ind].x = nx;

            kvec[y][x][vec[i]] = 0;
            kvec[ny][nx][nextind] = now_ind;
            nextind++;
        }
    }
    else  if (arr[ny][nx] == 1)
    {
        for (int i = len-1; i >=0 ; i--)
        {
            int now_ind = kvec[y][x][vec[i]];

            kpos[now_ind].y = ny;
            kpos[now_ind].x = nx;

            kvec[y][x][vec[i]] = 0;
            kvec[ny][nx][nextind] = now_ind;
            nextind++;
        }
    }

    if (nextind >= 4)
        endgame = true;

}

int main()
{
   
    cin >> n>>k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= k;i++)
    {
        scanf("%d %d %d", &kpos[i].y, &kpos[i].x, &kpos[i].dir);
        kvec[kpos[i].y][kpos[i].x][0] = i;
    }

    int count = 1;
    while (true)
    {
        if (count > 1000)
        {
            cout << -1;
            return 0;
        }
        for (int i = 1; i <= k; i++)
        {
            int y = kpos[i].y;
            int x = kpos[i].x;
            pair<int, int> next = nextFunc(kpos[i].dir);
            int ny = kpos[i].y + next.first;
            int nx = kpos[i].x + next.second;

            if (reverse_move(ny,nx))
            {
                kpos[i].dir = changeDir(kpos[i].dir); ///방향바뀜

                pair<int, int> next = nextFunc(kpos[i].dir);
                int ny = kpos[i].y + next.first;
                int nx = kpos[i].x + next.second;

                if (reverse_move(ny, nx)) //두번연속은 놉
                {
                    continue;
                }
                else
                {
                    mymove(i, ny, nx);
                }

            }
            else
            {
            

                mymove(i, ny, nx);
                
            }

            if (endgame)
            {
                cout << count;
                return 0;
            }
        }

    

            count++;
    }

    return 0;
}