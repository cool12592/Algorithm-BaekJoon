#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>

#define inf 987654321

using namespace std;

int parent[10001];
int n, k;

int find(int a)
{
    if (a == parent[a]) return parent[a];

    return parent[a] = find(parent[a]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a > b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    
    cin >> n;
    vector<int>vec1(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec1[i]);

    }
    
    cin >> k;
    vector<int>vec2(k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &vec2[i]);
        parent[i] = i;
    }
parent[k] = k;
    sort(vec1.begin(), vec1.end(), greater<int>());
    sort(vec2.begin(), vec2.end(), greater<int>());

    if (vec1[0] < vec2[0]) //젤쏀애가 젤무거운거못들면 gg (젤무거운거들면 다 들수있음)
    {
        cout << -1;
        return 0;
    }
    int ind = 0;
    int time = 1;
    bool b = false;


    vector<int>vec3(n,-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (vec1[i] >= vec2[j])
            {
                vec3[i] = j;//출발지점
                break;
            }
        }
    }

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (find(vec3[i]) == k || vec3[i]==-1)
                continue;

            unite(vec3[i], find(vec3[i])+1);
            ind++;

            if (ind == k)
            {
                b = true;
                break;
                
            }
            
        }
        if (b)
        {
            cout << time;
            return 0;
        }
        time++;
    }
    return 0;
}