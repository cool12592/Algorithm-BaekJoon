#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>

#define inf 987654321
using namespace std;


int parent[10001];
int need_money[10001];
int find(int a)
{
    if (parent[a] == a) return a;
    else
        return parent[a] = find(parent[a]); //bool값은 ==이거고 지금이건 결과값이 리턴임
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if (need_money[a] > need_money[b])
        parent[a] = b;//돈필요작은애가 루트
    else
        parent[b] = a;
}

int main()
{
    int n,m,k;
    cin >> n>>m>>k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &need_money[i]);
        parent[i] = i;
    }
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        unite(a, b);
    }
    int all_need_money=0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
            all_need_money += need_money[i];
    }

    if (all_need_money <= k)
    {
        cout << all_need_money;
    }
    else
    {
        cout << "Oh no";
    }
   
    return 0;
}