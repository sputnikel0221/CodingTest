#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int c2 = 0, c5 = 0;
    for(int i=1; i<=N; i++)
    {
        int n = i;

        // 2개수 확인
        while(true)
        {
            if(n%2==0)
            {
                c2++;
                n/=2;
            }
            else
            {
                break;
            }
        }

        // 5개수 확인
        while(true)
        {
            if(n%5==0)
            {
                c5++;
                n/=5;
            }
            else
            {
                break;
            }
        }
    }

    // 10을 만들기 위한 개수
    cout << min(c2, c5);

    return 0;   
}