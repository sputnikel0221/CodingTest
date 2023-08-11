#include <iostream>
using namespace std;

int N, M;

bool passIdx[401][401]; // i에서 j로 갈 수 있는가 = i가 j의 전인가

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 1 연결 입력
    while(M--)
    {
        int from, to;
        cin >> from >> to;
        passIdx[from][to] = true;
    }

    // 2 k를 거쳐서 갈 수 있는 점들도 설정
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(passIdx[i][k] && passIdx[k][j])
                {
                    passIdx[i][j] = true;
                }
            }
        }
    }
    

    // 3 passIdx값에 따라, 조건에 맞춰 출력
    int S;
    cin >> S;
    while(S--)
    {
        int from, to;
        cin >> from >>to;

        if(passIdx[from][to])
        {
            cout << -1 << "\n";
        }
        else if(passIdx[to][from])
        {
            cout << 1 << "\n";;
        }
        else
        {
            cout << 0 << "\n";
        }
    } 

    return 0;   
}