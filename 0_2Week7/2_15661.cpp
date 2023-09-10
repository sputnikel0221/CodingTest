#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[21];
int arr[21][21];
vector<int> v;

int result=987654321;

void DFS(int num)
{
    // N/2이상을 비교할 필요가 없는게, 한쪽을 구하면 나머지가 정해지기 때문.
    // 그러니까  12/3 인 경우와, 3/12 인 경우가 같아서 구하는게 의미없다.
    if(v.size()>N/2)
    {
        return;
    }

    if(v.size()>=1)
    {
        // v 속 원소의 값은 상관이 없다. visited만 체크
        int s_result=0, l_result=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1; j<=N;j++)
            {
                if(visited[i]==true&&visited[j]==true)
                {
                    s_result += arr[i][j];
                }
                if(visited[i]==false&&visited[j]==false)
                {
                    l_result += arr[i][j];
                }
            }
        }
        //cout << s_result << " : " << l_result <<"\n";
        result = min(result, abs(s_result-l_result));
    }
    //else  // 이게 존재한다면, if문을 끝으로 result를 구하고 DFS가 return되어
            // 다음 원소를 추가하지 않았을 것이다.
    {
        for(int i=num;i<=N;i++)   // num~N까지로 수정
        {
            if(!visited[i])
            {
                visited[i] = true;
                v.push_back(i);
                DFS(i);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> arr[i][j];
        }
    }

    DFS(1); // 시작이 1이어야 함

    cout << result;

    return 0;   
}