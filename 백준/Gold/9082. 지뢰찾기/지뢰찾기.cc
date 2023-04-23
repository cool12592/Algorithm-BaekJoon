#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
#define inf -987654321
string str1, str2;

int dfs(vector<int>& vec, vector<int>& proceed)
{
    int ind = proceed.size();

    if (vec.size() == ind)
    {
        if (vec[vec.size() - 1] == 0)
            return 0;
        else
            return inf;
    }

    bool b = false;
    if (proceed[ind - 1] == 1)
    {
        vec[ind]--;
        b = true;
    }

    int res = 0;
    if (vec[ind - 1] >= 2 || vec[ind-1] <= -1)
    {
        return inf;
    }

    if (str2[ind] == '*')
    {
        if (vec[ind - 1] != 1)
            return inf;

        proceed.push_back(1);
        vec[ind - 1]--;
        vec[ind]--;

        res += dfs(vec, proceed) +1;

        proceed.pop_back();
        vec[ind - 1]++;
        vec[ind]++;
    }
    else
    {
        if (vec[ind - 1] == 1)
        {
            proceed.push_back(1);
            vec[ind - 1]--;
            vec[ind]--;


            res += dfs(vec, proceed)+1;

            proceed.pop_back();
            vec[ind - 1]++;
            vec[ind]++;

        }
        else if (vec[ind - 1] == 0)
        {
            proceed.push_back(0);
            res += dfs(vec, proceed);
            proceed.pop_back();

        }
    }
    if (b)
    {
        vec[ind]++;
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int>vec(n);
      
        cin >> str1;
        cin >> str2;
        for (int i = 0; i < n; i++)
        {
            vec[i] = str1[i] - '0';
        }
        int ans = 0;
        vector<int> proceed;
        if (str2[0] == '*')
        {
            proceed.push_back(1);
            vec[0]--;
            ans = dfs(vec, proceed) + 1;
        }
        else
        {
            if (vec[0] == 0)
            {
                proceed.push_back(0);
                ans = dfs(vec, proceed);
            }
            else if (vec[0] == 1)
            {
                proceed.push_back(0);
                ans = dfs(vec, proceed);
                proceed.pop_back();

                proceed.push_back(1);
                vec[0]--;
                ans = max(ans, dfs(vec, proceed) + 1);
            }
            else
            {
                proceed.push_back(1);
                vec[0]--;
                ans = dfs(vec, proceed) + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}