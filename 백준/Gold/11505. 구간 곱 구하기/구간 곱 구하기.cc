#include <iostream>
#include <math.h>
#include<vector>
//지금이 5시 7분이니까 대략 4시 30분시작? 40분시작? 40분이라치자 
using namespace std;

class SegmentTree
{
private:
    long long* nodes;
     long long * A;

    long long init(int index, int start, int end)
    {
        if (start == end)
            nodes[index] =A[start];
        else
            nodes[index] =
            (init(index*2+1,start,(start+end)/2) * init(index * 2 + 2, (start + end) / 2  +1, end)) % 1000000007;
        

        return nodes[index]% 1000000007;
    }
public:
    SegmentTree(int N, long long* A) {
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
        return (getmul(index * 2 + 1, start, mid, left, right)*
         getmul(index * 2 + 2, mid + 1, end, left, right))% 1000000007;
    }
    //1:05
    //다른건 다 커버가되는데 기존값이 0일때는 
    //위에서부터변경이안되기때문에 (아 분수도 안되니까 애초에안됬겠다 정수형으론)
    //밑으로갔다 다시올라가야됨 (내려가서 트리에서그수찾아서 고치고 위로가면서 다시 새로고침)
    //여기서 change_index는 배열기준임 트리기준이아닌

    //트리기준의 changed_index를 찾기위해 밑으로가는과정
    void update(int changed_index, int change_num, int index, int start, int end)
    {
        
        if (changed_index < start || changed_index > end)
            return;

       // nodes[index] *= diff;

        if (start != end) {
            int mid = (start + end) / 2;
            update(changed_index, change_num, index * 2 + 1, start, mid);
            update(changed_index, change_num, index * 2 + 2, mid + 1, end);
        }
        if (start == end) //해당노드
        {
            nodes[index] = change_num; //트리기준인덱스를찾음
            if (index != 0)
            {
                if (index % 2 == 0)
                    update_up(index / 2 - 1); //트리의 부모인덱스
                else
                    update_up(index / 2); //트리의 부모인덱스
            }
        }
    }
    //해당인덱스부터 위로가면서 자식들 곱한값으로 다시 업데이트함
    void update_up(int tree_index)
    {

        nodes[tree_index] =( nodes[tree_index * 2 + 1] * nodes[tree_index * 2 + 2])% 1000000007;//자식들 곱함

        if (tree_index != 0) 
        {
            if (tree_index % 2 == 0)
                update_up(tree_index / 2 - 1); //트리의 부모인덱스
            else
                update_up(tree_index / 2); //트리의 부모인덱스
        }
    }

};

int main()
{
    int n, m,k;
    scanf("%d %d %d", &n , &m,&k);

    long long arr[1000001];
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
  
    SegmentTree sg(n, arr);
    for (int i = 0; i < m+k; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        if (a == 1)
        {
            long long c;//바꿀수
            scanf("%lld", &c);
           

            sg.update(b - 1,c,0,0,n-1);
            arr[b - 1] = c;
        }
        else if (a == 2)
        {
            int c; //b-c까지곱
            scanf("%d", &c);
            printf("%lld\n",sg.getmul(0, 0, n - 1, b-1, c-1));
        }
       
    }
    return 0;
}
