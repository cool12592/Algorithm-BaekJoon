#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
//코딩시작 8시12분 (풀이고민은 많이함)
#include<unordered_map>
using namespace std;
#define max 1000001
//순서 맞추면서
//중간 탐색도 계속 가능해야하고
//erase까지 되야한다
//이럴땐 erase상황은 실제 빼지않고 0으로하고 세그먼트트리 이분탐색 구간합 그에맞는거 찾는다
typedef long long ll;
class SegmentTree
{
private:
    ll* nodes;
    int* A;

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
    SegmentTree(int N, int* A) {
        int h = (int)ceil(log2(N));
        int node_size = 1 << (h + 1);
        nodes = new ll[node_size];

        this->A = A;
        init(0, 0, N - 1);
    }
    ~SegmentTree() {
        delete[] nodes;
    }
    int Qurey(int index, int start, int end, int target)
    {
        if (start == end)
            return end; //아 무조건 리프까지가야하네



        int mid = (start + end) / 2;
        //처음과 더 가까운애로 해야되서 무조건 왼쪽부터
        //왼쪽없으면 오른쪽으로 가는데 이때 target에 왼쪽만큼 빼줌
        //왜냐 3개찾는데 왼쪽에 한개있음
        //그럼 오른쪽에서 두번째꺼찾음됨(3(카운트)-1(ㅇ왼쪽에있는개수))
        //https://yabmoons.tistory.com/472
        
        //왼쪽에있다
        if (target <= nodes[index * 2 + 1])
            return Qurey(index * 2 + 1, start, mid, target);
       //없어서 오른쪽 보는데 이때 target 에 왼쪽만큼 빼준다
         return Qurey(index * 2 + 2, mid + 1, end, target- nodes[index * 2 + 1]);
       
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

    int n;
    cin >> n;
    int a, b, c;
    int arr[max] = { 0, };
    SegmentTree sg(max, arr); //처음 싹다0으로
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 2)
        {
            scanf("%d %d", &b, &c);
            arr[b] += c;
            sg.update(b, c, 0, 0, max - 1);
        }
        if (a == 1)
        {
            scanf("%d", &b);
            int target_index = sg.Qurey(0, 0, max-1, b);
            printf("%d\n", target_index);
            sg.update(target_index, -1, 0, 0, max - 1);//하나빼줌
        }
    }


    return 0;
}
