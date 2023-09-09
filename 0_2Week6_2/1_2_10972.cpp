#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> my_next_permutation(vector<int> vv, int n);
vector<int> v;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    //if(next_permutation(v.begin(), v.end()))  // 이 부분만 수정하면 됨
    if(prev_permutation(v.begin(), v.end()))
    {
        for(int i=0;i<N;i++)
        {
            cout << v[i] << ' ';
        }
    }
    
    else
    {
        cout << -1;
    }

    /*  
    v = my_next_permutation(v, N);
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << ' ';
    }
    */

    return 0;
}

vector<int> my_next_permutation(vector<int> a, int n)
{
    vector<int> vv = a;

    int i = n - 1;                      // 인덱스는 0~n-1이기 때문.
    while (i > 0 && vv[i - 1] >= vv[i]) // 5 4 3 2 1 이렇게 내림차순인걸 확인
    {
        i -= 1;
    }
    if (i <= 0)
    {
        // return false;
    }

    int j = n - 1;
    while (vv[i - 1] >= vv[j]) // 내림차순 바로 이전 수보다 첫 큰 j를 찾기
    {
        j -= 1;
    }

    swap(vv[i - 1], vv[j]); // 그 둘을 swap하면 다음 순서가 됨

    j = n - 1;
    while (i < j)
    {
        swap(vv[i], vv[j]);
        i += 1;
        j -= 1;
    }

    return vv;
}