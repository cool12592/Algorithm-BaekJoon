#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#include<map>
#define inf 987654321
using namespace std;
vector<vector<int>>arr(51,vector<int>(51));


    
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int a, b, c;
    double sum=0;
    double number=0;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &a,&b,&c);
        int temp = a;
        while (a <= n)
        {
            if(b==0)
                rotate(arr[a].begin(),arr[a].begin()+m - c ,arr[a].begin()+m);
            else
                rotate(arr[a].begin(), arr[a].begin() + c, arr[a].begin() + m);

            a += temp;

           

        }

        sum = 0;
        number = 0;
        vector<pair<int, int>> rec;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {

                if (arr[i][j] == 0) continue;
                sum += arr[i][j];
                number++;
                if (arr[i][j] == arr[i][j + 1])
                {
                    rec.push_back({ i,j });
                    rec.push_back({ i,j + 1 });
                }

                if (i == n) continue;

                if (arr[i][j] == arr[i + 1][j])
                {
                    rec.push_back({ i,j });
                    rec.push_back({ i + 1,j });
                }

            }
            if (arr[i][m - 1] == 0) continue;
            sum += arr[i][m-1];
            number++;
            if (arr[i][m-1] == arr[i][0])
            {
                rec.push_back({ i,m-1 });
                rec.push_back({ i,0 });
            }
            if (i == n) continue;
            if (arr[i][m - 1] == arr[i+1][m-1])
            {
                rec.push_back({ i,m-1 });
                rec.push_back({ i+1,m - 1 });
            }
        }

        for (auto ind : rec)
        {
            arr[ind.first][ind.second] = 0;
        }



        if (rec.size() == 0)
        {
            double num2 = sum / number;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (arr[i][j] == 0) continue;
                    if (arr[i][j] < num2)
                        arr[i][j]++;
                    else if (arr[i][j] > num2)
                        arr[i][j]--;
                }
            }

        }


    }
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m ; j++)
        {

            if (arr[i][j] == 0) continue;
            sum += arr[i][j];
        }
    }
    cout << (int)sum;


    return 0;
}