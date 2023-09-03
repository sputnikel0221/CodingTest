#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;

    cin >> T;

    vector<int> sum1;
    vector<int> sum2;
    while(T--)
    {
        // 초기화
        sum1.clear();
        sum2.clear();

        // 입력값 받기
        cin >> N;
        while(N--)
        {
            int num;
            cin >> num;

            sum1.push_back(num);
        }   

        




    }

    return 0;   
}