#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;

//4시 37분 (문제풀이7분뺌)

string dfs(string s1,string s2,int k,int ind)
{
    if (k == 0)
        return s1;
    
    if (ind == s1.size()) //끝지났는데 k가 남은상황
    {
        int visit[10] = { 0, };
        for (int i = 0; i < s1.size(); i++)
        {
            if (visit[s1[i] - '0'] == 1) //중복수있다(그거끼리바꾸면됨)
                return s1;
            visit[s1[i] - '0'] = 1;
        }

        while (k--)
        {
            char temp = s1[s1.size() - 1];
            s1[s1.size() - 1] = s1[s1.size() - 2];
            s1[s1.size() - 2] = temp;

            if (s1[0] == '0')
            {
                return "0";
            }
        }
        return s1;
    }
    if (s1[ind] == s2[ind])
        return dfs(s1, s2, k, ind + 1); //스왑할게없으면 k안 줄어듬
   
    string temp = "0";
    
    //뒤에 바꿀수있는수가 여러개있으면 다 바꿔보고 그중 젤 결과좋은애로 채택
    for (int j = ind + 1; j < s1.size(); j++)
    {
        if (s1[j] == s2[ind])
        {

            s1[j] = s1[ind];
            s1[ind] = s2[ind];
            temp = max(temp, dfs(s1, s2, k - 1, ind + 1));
            //원래대로되돌리기
            s1[ind] = s1[j];
            s1[j] = s2[ind];
        }
    }
    return temp;
   
   
   

}
//1시10분
int main()
{
    string vec1;
    vector<int> vec2;
    string n;
    int  k;
    cin >> n >> k;
   
    for (int i = 0; i < n.size(); i++)
    {
      //  vec1.push_back(n[i] - '0');
        vec2.push_back(n[i] - '0');
    }
    sort(vec2.begin(), vec2.end(),greater<int>());
    vec1 = n;

    if (vec1.size() == 1)
    {
        cout << -1;
        return 0;
    }
    string s2;
    for (int i = 0; i < n.size(); i++)
    {
        s2 += char(vec2[i] + 48);
    }
   string mys= dfs(n, s2, k, 0);
   

    if (mys[0] == '0') cout << -1;
    else
    {
      
       
        cout << mys;
    }
    
    return 0;
} 