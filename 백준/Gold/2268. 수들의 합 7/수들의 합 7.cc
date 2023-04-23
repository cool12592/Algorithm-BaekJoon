#include <iostream>
#include <math.h>
#include<vector>
#include<algorithm>
//지금이 5시 7분이니까 대략 4시 30분시작? 40분시작? 40분이라치자 
using namespace std;

class SegmentTree
{
private:
    long long* nodes;
    int* A;

    long long init(int index, int start, int end)
    {
        if (start == end)
            nodes[index] = A[start];
        else
            nodes[index] =
            (init(index * 2 + 1, start, (start + end) / 2) + init(index * 2 + 2, (start + end) / 2 + 1, end));


        return nodes[index];
    }
public:
    SegmentTree(int N, int* A) {
        int h = (int)ceil(log2(N));
        int node_size = 1 << (h + 1);
        nodes = new long long[node_size]; //최소 최대순 최소는 자식노드둘 최소중 더 작은애 최대는 자식노드 둘 최대중 더 큰애
                                               //리프노드는 같은값2개 최소도 최대도 같음

        this->A = A;
        init(0, 0, N - 1);
    }
    ~SegmentTree() {
        delete[] nodes;
    }
    long long getsum(int index, int start, int end, int left, int right)
    {
        //구하려는 범위가 밖에 있는 경우
        if (left > end || right < start)
            return 0;
        else if (left <= start && right >= end)
            return nodes[index];

        int mid = (start + end) / 2;
        return (getsum(index * 2 + 1, start, mid, left, right) +
            getsum(index * 2 + 2, mid + 1, end, left, right));
    }
    
    void update(int changed_index, int dif, int index, int start, int end)
    {

        if (changed_index < start || changed_index > end)
            return;

         nodes[index] += dif;

        if (start != end) {
            int mid = (start + end) / 2;
            update(changed_index, dif, index * 2 + 1, start, mid);
            update(changed_index, dif, index * 2 + 2, mid + 1, end);
        }
       
    }
    

};

int main()
{
    int n, m, k;
    scanf("%d %d", &n, &m);

    int arr[1000001] = { 0, }; //원소당최대값 백만
   

    SegmentTree sg(n, arr);
    for (int i = 0; i < m ; i++)
    {
        int a, b, c;
        
        scanf("%d %d %d", &a, &b, &c);
        vector<int>vec = { b,c };
        if (a == 1) //바꾸기
        {
            int dif = c - arr[b - 1];
            sg.update(b - 1, dif, 0, 0, n - 1);
            arr[b - 1] = c;
        }
        else if (a == 0)
        {
            //이문제는 b>c일수도있음
            sort(vec.begin(), vec.end());
            printf("%lld\n", sg.getsum(0, 0, n - 1, vec[0]-1, vec[1]-1));
        }

    }
    return 0;
}
