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


vector<vector<int>> tree;
vector<vector<int>> adj2;
vector<vector<int>> pos_vec;

bool cmp(vector<int>a,vector<int> b)
{
    if (a[1] < b[1])
        return true;
    if (a[1] > b[1])
        return false;

    //level같은경우
    //가로비교
    if (a[0] < b[0]) return true;
    if (a[0] > b[0]) return false;
}

int dfs(int now, int level)
{
   
    pos_vec[now][1] = level;

    int all_child_node = 0;
    int a = 0;
    int b = 0;
    if(adj2[now][0]!=-1)
        a = dfs(adj2[now][0], level + 1)+1;//왼쪽자식의 총 합
    if(adj2[now][1]!=-1)
        b = dfs(adj2[now][1], level + 1)+1;
    
    pos_vec[now][0] = a;
    all_child_node = a + b;
    return all_child_node;
    

}
void dfs2(int now, int standard)
{

    pos_vec[now][0] += standard + 1;

   
    if (adj2[now][0] != -1)
        dfs2(adj2[now][0], standard);
    if (adj2[now][1] != -1)
        dfs2(adj2[now][1], pos_vec[now][0]);

  


}
int main()
{
   
    int n;
    cin >> n;
    int a, b, c;
    adj2.resize(n + 1, vector<int>(2));
    pos_vec.resize(n + 1, vector<int>(2));
    vector<int> who_root(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        adj2[a][0] = b;
        adj2[a][1] = c;
        if(b!=-1)
        who_root[b] = 1;
        if(c!=-1)
        who_root[c] = 1;
    }
    int root = 0;
    for(int i=1;i<=n;i++)
        if (who_root[i] == 0)
        {
            root = i;
            break;
        }
    
    dfs(root, 1);
    dfs2(root, 0);
    sort(pos_vec.begin(), pos_vec.end(), cmp);
    int max_leve = pos_vec[pos_vec.size() - 1][1];
    tree.resize(max_leve+1);


    for (int i = 1; i <= n; i++)
    {
        int level = pos_vec[i][1];
        tree[level].push_back(pos_vec[i][0]);
        
    }
    int answer = 0;
    int answer_level = 0;
    for (int level = 1; level <= max_leve; level++)
    {
        int len = tree[level].size();
        int temp = tree[level][len - 1] - tree[level][0] + 1;
        if(answer<temp)
        {
            answer = temp;
            answer_level = level;
        }
    }
    cout << answer_level << " " << answer;
    return 0;
}