#include<iostream>
#include<memory.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;


//생각해보니 bfs라 젤먼저 간애가 젤빠른경우잖아?? 이경우는아닌가??
int main() {
   
    int a, b;
    cin >> a >> b;

  
    vector<int> vec;
    vec.push_back(b);
    while (true)
    {
        int s = vec.size();
        if (vec[vec.size() - 1] + s > 500000)
            break;
        vec.push_back(vec[vec.size()-1]+s);
    }


    queue<pair<int, int>>q;
    q.push({ a,0 });

    int maxtime = vec.size() - 1;
    vector<vector<int>> visit(500001,vector<int>(2,-1));
    visit[a][0] = 0;

    while (q.size() > 0)
    {
        pair<int, int> now = q.front();
        q.pop();
        int sec = now.second;
        int num = now.first;
       // if (maxtime < sec) //동생은 이시간에 이미 떠남...
       //     continue;

       // if (vec[sec]  == num)
       // {
       //     cout << sec;
       //     return 0;
      //  }
   
   

     /*   if (sec == 3 && num == 14)
            cout << 1;
        if (sec == 2 && num == 15)
            cout << 1;
        if (sec == 1 && num == 16)
            cout << 1;
        if (sec == 4 && num == 15)
            cout << 1;*/

     //   if (visit[num] < sec) //얘가들어올땐여기까지오는데이게 젤빠른경우였지만 그뒤에 더빠른경우가생김
       //     continue;



        if (num + 1 <= 500000 && visit[num + 1][(sec+1)%2]==-1)
        {
           // visit[num + 1] = sec + 1;
            q.push({ num + 1,sec + 1 });
            visit[num + 1][(sec + 1) % 2] = sec+1;
        }
        if (num - 1 >= 0 && visit[num - 1][(sec + 1) % 2]==-1)
        {
           // visit[num - 1] = sec + 1;
            q.push({ num - 1,sec + 1 });
            visit[num - 1][(sec + 1) % 2] = sec + 1;
        }
        if (num * 2  <=500000&& visit[num * 2][(sec + 1) % 2]==-1)
        {
          //  visit[num * 2] = sec + 1;
            q.push({ num * 2 ,sec + 1 });
            visit[num * 2][(sec + 1) % 2] = sec + 1;
        }
        
    }
 
    for (int i = 0; i <= maxtime; i++)
    {
        int target = vec[i];
        if (i % 2 == 0)
        {
            if (visit[target][0] != -1 && visit[target][0]<=i)
            {
                cout << i;
                return 0;
            }
        }
        else
        {
            if (visit[target][1] != -1 && visit[target][1] <= i)
            {
                cout << i;
                return 0;
            }
        }
    }


    cout << -1;
    return 0;
}
