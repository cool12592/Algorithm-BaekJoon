#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#define inf 987654321
//6시 20분 시작 읽고 풀이 10분
using namespace std;

struct node{
    pair<int, int> mal[4];
   
   
    int turn=0;
    int count=0;
   // vector<pair<int,int>>mini;

};
//1시10분
int main()
{
    pair<int, int> pos[] = { {0,0},{0,0},{0,0},{0,0} };
    vector<vector<pair<int, int>>> vec(5);
    for (int i = 0; i <= 20; i++)
    {
        vec[0].push_back({ i * 2,0 });
    }
    vec[1].push_back({ 10,0 });
    vec[1].push_back({ 13,0 });
    vec[1].push_back({ 16,0 });
    vec[1].push_back({ 19,0 });
    vec[1].push_back({ 25,0 });
   
    vec[2].push_back({ 20,0 });
    vec[2].push_back({ 22,0 });
    vec[2].push_back({ 24,0 });
    vec[2].push_back({ 25,0 });
    

    vec[3].push_back({ 30,0 });
    vec[3].push_back({ 28,0 });
    vec[3].push_back({ 27,0 });
    vec[3].push_back({ 26,0 });
    vec[3].push_back({ 25,0 });
   

    vec[4].push_back({ 25,0 });
    vec[4].push_back({ 30,0 });
    vec[4].push_back({ 35,0 });
    vec[4].push_back({ 40,0 });

    queue<node>q;
    node start;
    q.push(start);

    int move[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &move[i]);


    int answer = 0;

    int test = 0;
    while (q.size() > 0)
    {
        node now = q.front();
        q.pop();
        answer = max(answer, now.count);


       
        
       
            for (int i = 0; i < 4; i++)
            {
                int ny, nx, ncount;

                int y = now.mal[i].first;
                int x = now.mal[i].second;

                if (y == -1 && x == -1) //도착말
                    continue;

                if (now.turn >= 10)
                    continue;

                ny = y;
                nx = x + move[now.turn];

                test++;
                


                if (y >= 1 && y <= 3)
                {
                    if (nx >= vec[y].size() - 1)
                    {

                        
                        nx = nx - (vec[y].size() - 1);
                        ny = 4;
                    }
                }

                //if (vec[ny].size() <= nx || nx < 0) { //예외 발생
                //    throw string("Underflow!");
                //}

                if (nx >= vec[ny].size()) //끝을넘음
                {

                    if (ny == 0 || ny == 4) //도착
                    {
                        ncount = now.count;

                        node temp = now;
                        temp.mal[i] = { -1,-1 };
                        temp.turn += 1;
                        temp.count = ncount;
                       // temp.mini.push_back({ i,move[now.turn] });
                       // temp.mini.push_back({ now.count,  now.count });
                        q.push(temp);
                        continue;
                    }
                }

              //  if (vec[ny].size() <= nx || nx < 0) { //예외 발생
              //      throw string("Underflow!");
              //  }

                if (y == 0)
                {
                    if (vec[ny][nx].first == 10)
                    {
                        ny = 1;
                        nx = 0;
                    }
                    else if (vec[ny][nx].first == 20)
                    {
                        ny = 2;
                        nx = 0;
                    }
                    else if (vec[ny][nx].first == 30)
                    {
                        ny = 3;
                        nx = 0;
                    }
                }

                if (ny == 4 && vec[ny][nx].first == 40)
                {
                    ny = 0;
                    nx = vec[ny].size() - 1;
                }

                bool contin = true;
                for (int j = 0; j < 4; j++)
                {
                    if (i == j) continue;



                    if (now.mal[j].first == ny && now.mal[j].second == nx) //거기에 말이있다
                    {
                        contin = false;
                        break;
                    }


                }
                if (!contin) continue;

                if (vec[ny].size() <= nx || nx < 0 ) { //예외 발생
                    throw string("Underflow!");
                }


                node temp = now;

               // temp.mini.push_back({ i,move[now.turn] });
               // temp.mini.push_back({ now.count, vec[ny][nx].first });

                ncount = now.count + vec[ny][nx].first;



                temp.mal[i] = { ny,nx };
                temp.turn += 1;
                temp.count = ncount;

                q.push(temp);
            }
      
    }
   // cout << test<<endl;
    cout << answer;
    return 0;
}