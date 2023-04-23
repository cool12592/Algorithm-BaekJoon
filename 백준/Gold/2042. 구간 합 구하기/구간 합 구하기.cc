#include <iostream>
#include <math.h>
#include<vector>
typedef long long ll;
using namespace std;

class SegmentTree
{
private:
    ll* nodes;
    ll* A;

    ll init(int index, int start, int end)
    {
        if (start == end)
            nodes[index] = A[start];
        else
            nodes[index] =
            init(2 * index + 1, start, (start + end) / 2) +
            init(2 * index + 2, (start + end) / 2 + 1, end);

        return nodes[index];
    }
public:
    SegmentTree(int N, ll* A) {
        int h = (int)ceil(log2(N));
        int node_size = 1 << (h + 1);
        nodes = new ll[node_size];

        this->A = A;
        init(0, 0, N - 1);
    }
    ~SegmentTree() {
        delete[] nodes;
    }
    ll getSum(int index, int start, int end, int left, int right)
    {
        //구하려는 범위가 밖에 있는 경우
        if (left > end || right < start)
            return 0;
        else if (left <= start && right >= end)
            return nodes[index];

        int mid = (start + end) / 2;
        return getSum(index * 2 + 1, start, mid, left, right) +
            getSum(index * 2 + 2, mid + 1, end, left, right);
    }
    void update(int changed_index, ll diff, int index, int start, int end)
    {
        if (changed_index < start || changed_index > end)
            return;

        nodes[index] += diff;

        if (start != end) {
            int mid = (start + end) / 2;
            update(changed_index, diff, index * 2 + 1, start, mid);
            update(changed_index, diff, index * 2 + 2, mid + 1, end);
        }
    }
};

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n , &m, &k);

    long long arr[1000001];
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
  
    SegmentTree sg(n, arr);
    for (int i = 0; i < m + k; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            int b;//인덱스
            long long c;//값 arr[b-1]를 c로변경
            scanf("%d %lld", &b,&c);
            long long dif = c-arr[b - 1] ;
            arr[b - 1] = c;
            sg.update(b - 1, dif, 0, 0, n - 1);
        }
        else if (a == 2)
        {
            int b, c; //b인덱스부터 c인덱스까지의 부분합 나는0부터시작이라 b-1 c-1
            scanf("%d %d", &b, &c);
            cout << sg.getSum(0, 0, n - 1, b - 1, c - 1) << endl;
        }
    }
    return 0;
}
