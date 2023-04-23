#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#include<stack>
#include<unordered_map>
#define inf 987654321

using namespace std;

unordered_map<int, string> um;
string sol(int num)
{
    string str = "";
    while (true)
    {
        if (num <= 12 || num==17)
        {
            str += um[num];
            reverse(str.begin(), str.end());
            return str;
        }
        else
        {
            str += '8';
            num -= 7;
        }
    }
}

string sol22(int num)
{
    string str = "";
    while (true)
    {
        if (num == 2)
        {
            str += "1";
            return str;
        }
        else if (num == 3)
        {
            str += "7";
            return str;
        }
        else if(num%2!=0)//홀수
        {
            str += "7";
            num -= 3;
        }
        else
        {
            str += "1";
            num -= 2;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a;

    um[2] = "1";
    um[3] = "7";
    um[4] = "4";
    um[5] = "2";
    um[6] = "6";
    um[7] = "8";
    um[8] = "01"; //리버스
    um[9] = "81";//리버스
    um[10] = "22";//리버스
    um[11] = "02";//리버스
    um[12] = "82";//리버스
    um[17] = "002";//리버스
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        cout << sol(a) << " " << sol22(a);
        printf("\n");
    }

    return 0;
}