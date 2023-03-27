#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int answer;
    int this_score = 0;
    int sum_score = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> answer;
        if(answer==1){  //정답인 경우,
            this_score++;
            sum_score+=this_score;
        }
        else{
            this_score = 0;
        }
    }
    cout << sum_score;
    

    return 0;   
}