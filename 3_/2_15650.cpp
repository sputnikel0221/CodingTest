#include <iostream>
using namespace std;

int N, M;
int ans[9];
bool visited[9];

void DFS(int count, int max_visited){
    //1. 목적지인가?
    if(count == M){
        for(int i=0;i<M;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    //2. 연결된 곳을 순회
    for(int i=1;i<=N;i++){
        //3. 갈 수 있는가?
        if(max_visited < i && !visited[i]){
            //4. 체크인
            ans[count] = i; 
            visited[i] = true;
            
            //5. 갈 수 있으면 간다.
            DFS(count+1, i);

            //6. 체크아웃
            visited[i] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    DFS(0, 0);

    return 0;   
}