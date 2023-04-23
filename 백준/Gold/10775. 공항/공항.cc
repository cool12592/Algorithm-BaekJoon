#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
#include <unordered_map>
#include<string>
#include<map>
#include<set>
#include<list>

#define inf 987654321
using namespace std;


int parent[100001];

int find(int num)
{
    if (parent[num] == num) return num;

    return parent[num] = find(parent[num]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main()
{
   
    int n, m;
    cin >> n >> m;
    int num;
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        int x = find(num);
        if (x == 0)
            break;

        unite(x, x - 1);

        answer++;
    }
    
    cout << answer;

    return 0;
}