#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int tmp = N;

    int pow = 0; // 0부터 시작 //승수
    int ten = 1; // 10의 pow승

    int sum = 0;

    // 먼저 pow부터 구해야만 한다.
    while (tmp / 10 != 0)
    {
        pow += 1;
        ten *= 10;
        tmp /= 10;
    }


    // cout << pow << " // "<< ten << '\n';

    if (pow == 0)
    {
        sum += N * 1;
        cout << sum;
        return 0;
    }
    else
    {
        tmp = N - ten; // 215673 - 100000 = 115673+1개
        sum += (tmp+1) * (pow+1);

        //이제 규칙대로 하위 차항들을 더함
        while(pow-- > 0){
            ten /= 10;
            sum+=(pow+1) * 9*ten; //숫자자리수 * 숫자의 개수
        }
    }
   

    cout << sum;

    return 0;
}