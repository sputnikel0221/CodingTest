#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if(1<= N && N <=9)
    {
        cout << N;
        return 0;
    }
    // 10^0 1~9는 9*1 = 9자리
    // 10^1 10~99는 90*2 = 180자리
    // 10^2 100~999는 900*3 = 2700자리
    // 10^3 9000,4... 10^4 90000,5...

    // 자릿수 구하기
    int tenth = 1; // 1자릿수
    int num = N;
    while(true)
    {
        num/=10;
        tenth++;
        //cout << N << " " <<  tenth << "\n";

        if(num/10==0)
        {
            break;
        }
    }

    int zari = tenth;
    int result = 0;
    // 해당 단계 이전의 값들은 모두 더하고, 해당 단계는 차를 통해 계산
    while(tenth--)  // 3이면 2부터 시작
    {
        int q = 1;
        for(int i=0; i<tenth-1; i++)
        {
            q*=10;
        }

        result += 9*q * tenth;
    }
    
    int tenzari = zari-1;
    int mak = 1;
    while (tenzari--)
    {
        mak*=10;
    }
    
    int ea = N-mak+1; // 773-99    120인데 118이 왜나오지? 189
    result += ea*zari;

    cout << result;

    return 0;   
}