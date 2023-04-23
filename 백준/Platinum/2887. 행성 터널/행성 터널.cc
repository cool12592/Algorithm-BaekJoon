#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;

//로직 은근간단함
//xyz 모두 정렬하고 서로서로사이를 엣지로 생각해 엣지벡터에 싹집어넣음 x에서도y도z도
//이 싹 집어넣은 엣지 가중치순으로 정렬하고 
//크루스칼하면 끝
//크루스칼도 초간단
//엣지하나씩 까보면서 양쪽 정점의 부모가 다르다면
//두정점연결 unite로 (루트 같게만듬)


struct planet {
    int x, y, z, num;
};

struct edge {
    int weight, from, to;
};

bool cmp(edge& a, edge& b)
{
    return a.weight < b.weight; //오름차순
}

vector<edge> ed;
planet my_planet[100000];
int parent[100000];

int find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
 
}
void unite(int x, int y) {
    x = find(x); //x의루트
    y = find(y); //y의루트

    parent[y] = x; //두개가 루트였는데 한루트를 다른 루트의 부모로만들어버림
}

int n, i;

int main() {
    cin >> n;
    vector<pair<int,int>> x_sort(n);
    vector< pair<int, int>> y_sort(n);
    vector< pair<int, int>> z_sort(n);
    for (i = 0; i < n; ++i) {
        scanf("%d %d %d", &my_planet[i].x, &my_planet[i].y, &my_planet[i].z);

        my_planet[i].num = i;
        parent[i] = i;

        x_sort[i] = { my_planet[i].x,i };
        y_sort[i] = { my_planet[i].y,i };
        z_sort[i] = { my_planet[i].z,i };

    }

    sort(x_sort.begin(), x_sort.end());
    for (i = 0; i < n - 1; ++i)
        ed.push_back({ abs(x_sort[i].first- x_sort[i + 1].first), x_sort[i].second, x_sort[i + 1].second });


    sort(y_sort.begin(), y_sort.end());
    for (i = 0; i < n - 1; ++i)
        ed.push_back({ abs(y_sort[i].first - y_sort[i + 1].first), y_sort[i].second, y_sort[i + 1].second });

    sort(z_sort.begin(), z_sort.end());
    for (i = 0; i < n - 1; ++i)
        ed.push_back({ abs(z_sort[i].first - z_sort[i + 1].first), z_sort[i].second, z_sort[i + 1].second });

    sort(ed.begin(), ed.end(),cmp);

    int answer = 0;
    int count = 0;

    //크루스칼
    for (int i = 0; i < ed.size(); i++)
    {
        if (find(ed[i].to) != find(ed[i].from)) //부모가달라야붙일수있음
        {
            count++; //연결된수

            unite(ed[i].to, ed[i].from); //루트같은걸로통합
            answer += ed[i].weight;

            if (count == n - 1) //다연결되면
                break;
        }

    }



  
    printf("%d", answer);

    return 0;
}