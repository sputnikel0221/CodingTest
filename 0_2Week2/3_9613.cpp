#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b!=0)
    {
        c = a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    // 테스트케이스 시작
    while(T--)
    {   
        // TC별 개수 N
        int N;
        cin >> N;

        // 벡터에 입력받기
        vector<int> arr;
        for(int i=0;i<N;i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        // 모든 쌍에 대하여 gcd를 구하고 값을 저장.
        long long result = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                result += gcd(arr[i], arr[j]);
            }
        }

        // 출력
        cout << result << "\n";
    }

    return 0;   
}