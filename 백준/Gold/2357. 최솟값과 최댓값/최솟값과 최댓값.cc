#include <iostream>
#include <math.h>
#include<vector>
//지금이 5시 7분이니까 대략 4시 30분시작? 40분시작? 40분이라치자 
using namespace std;

class SegmentTree
{
private:
    pair<int,int>* nodes;
    int* A;

    pair<int,int> init(int index, int start, int end)
    {
        if (start == end)
            nodes[index] = { A[start],A[start] };
        else
        {
            pair<int, int> left_child = init(2 * index + 1, start, (start + end) / 2);
            pair<int, int> right_child = init(2 * index + 2, (start + end) / 2 + 1, end);
            nodes[index] =
            { min(left_child.first,right_child.first),max(left_child.second,right_child.second)
            };
        }

        return nodes[index];
    }
public:
    SegmentTree(int N, int* A) {
        int h = (int)ceil(log2(N));
        int node_size = 1 << (h + 1);
        nodes = new pair<int,int>[node_size]; //최소 최대순 최소는 자식노드둘 최소중 더 작은애 최대는 자식노드 둘 최대중 더 큰애
                                               //리프노드는 같은값2개 최소도 최대도 같음

        this->A = A;
        init(0, 0, N - 1);
    }
    ~SegmentTree() {
        delete[] nodes;
    }
    pair<int,int> get_minmax(int index, int start, int end, int left, int right)
    {
        //구하려는 범위가 밖에 있는 경우
        if (left > end || right < start)
            return { 1000000001,0 };
        else if (left <= start && right >= end)
            return nodes[index];

        int mid = (start + end) / 2;
        pair<int,int> left_child = get_minmax(index * 2 + 1, start, mid, left, right);
        pair<int, int> right_child= get_minmax(index * 2 + 2, mid + 1, end, left, right);
        return { min(left_child.first,right_child.first),
         max(left_child.second,right_child.second)};
    }
   /* void update(int changed_index, int diff, int index, int start, int end)
    {
        if (changed_index < start || changed_index > end)
            return;

        nodes[index] += diff;

        if (start != end) {
            int mid = (start + end) / 2;
            update(changed_index, diff, index * 2 + 1, start, mid);
            update(changed_index, diff, index * 2 + 2, mid + 1, end);
        }
    }*/
};

int main()
{
    int n, m;
    scanf("%d %d", &n , &m);

   int arr[100001];
    for (int i = 0; i < n; i++)
        scanf("%intd", &arr[i]);
  
    SegmentTree sg(n, arr);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d %d", &a,&b );

        pair<int, int> sol = sg.get_minmax(0, 0, n - 1, a-1, b-1);
        printf("%d %d\n",sol.first, sol.second);
    }
}
