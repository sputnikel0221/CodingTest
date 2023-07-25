#include <iostream>
#include <queue>
using namespace std;

bool visited[101] = {0, };
bool connection[101][101] =  {0, };
int N; //컴퓨터 개수
int T; //연결 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;
    cin >> T;

    int from;
    int to;

    //1. 모든 연결의 쌍을 connection 배열에 저장
    for(int i=0; i<T; i++)
    {
        cin >> from;
        cin >> to;

        connection[from][to] = 1;
        connection[to][from] = 1;
    }

    //2. DFS나 BFS를 돌며 연결된 곳 순환

    // BFS를 활용
    queue<int> nextCom;
    nextCom.push(1);    //1번 컴부터 시작
    visited[1] = true;
    int count = 0;
    while(!nextCom.empty())
    {
        // 1. Queue에서 꺼내옴
        int num = nextCom.front();
        nextCom.pop();

        // 2. 연결된 곳을 순회
        for(int i=0; i<101; i++)
        {
            // 3. 연결되었고, 실제로 갈 수 있는가?
            if(connection[num][i]==1 && visited[i]==false)
            {
                // 4.체크인
                visited[i] = true;
                // 5. Queue에다 넣음
                nextCom.push(i);      
                count++;
                //cout<< num << " " << i << endl;          
            }
        }

    }

    cout << count << endl;

    return 0;   
}