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
            (init(index * 2 + 1, start, (start + end) / 2) * init(index * 2 + 2, (start + end) / 2 + 1, end));


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
    long long getmul(int index, int start, int end, int left, int right)
    {
        //구하려는 범위가 밖에 있는 경우
        if (left > end || right < start)
            return 1;
        else if (left <= start && right >= end)
            return nodes[index];

        int mid = (start + end) / 2;
        return (getmul(index * 2 + 1, start, mid, left, right) *
            getmul(index * 2 + 2, mid + 1, end, left, right));
    }

    void update(int changed_index, int change_num, int index, int start, int end)
    {

        if (changed_index < start || changed_index > end)
            return;

        //nodes[index] += dif;

        if (start != end) {
            int mid = (start + end) / 2;
            update(changed_index, change_num, index * 2 + 1, start, mid);
            update(changed_index, change_num, index * 2 + 2, mid + 1, end);
        }
        if (start == end)
        {
            nodes[index] = change_num;
            if (index == 0) return;
            int  tree_index = index;
            if (tree_index % 2 == 0)
            {
                update_up(tree_index / 2 - 1);
            }
            else
            {
                update_up(tree_index / 2);
            }


        }

    }

    void update_up(int tree_index)
    {
        nodes[tree_index] = nodes[tree_index * 2 + 1] * nodes[tree_index * 2 + 2];
        if (tree_index == 0) return;
        if (tree_index % 2 == 0)
        {
            update_up(tree_index / 2 - 1);
        }
        else
        {
            update_up(tree_index / 2);
        }

    }


};

void change_num(int& num)
{
    if (num > 0) num = 1;
    else if (num < 0) num = -1;
    else num = 0;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {

        long long result = 0;

        int arr[100001] = { 0, }; //원소당최대값 백만
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            change_num(arr[i]);
        }

        SegmentTree sg(n, arr);
        for (int i = 0; i < m; i++)
        {
            char a;
            int b, c;

            scanf(" %c", &a);
            scanf("%d %d", &b, &c);
           
            if (a == 'C') //바꾸기
            {
                change_num(c);
                sg.update(b - 1, c, 0, 0, n - 1);
                arr[b - 1] = c;

            }
            else if (a == 'P')
            {
                result = sg.getmul(0, 0, n - 1, b - 1, c - 1);
                if (result > 0)
                    printf("+");
                else if (result < 0)
                    printf("-");
                else
                    printf("0");
            }

        }
        printf("\n");
    }
    return 0;
}
