#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;


    int result = -1; // result의 초기값은 절대 gdcd가 될 수 없는 값으로 둔다.
    while (N--)
    {
        int n;
        cin >> n;
        
        // 입력받는 점에 대해, 시작점과의 거리를 구함.
        int distance = (S > n) ? (S - n) : (n - S);

        // result가 아무 값도 없다면, 처음 distance를 그냥 넣음.
        if(result==-1)
        {
            result = distance;
        }
        // result가 존재하면, 해당 result와 현재 distance의 gcd를 구하고,
        // gcd를 result로 둠. 3수의 gcd를 구한다면, 2수의 gcd와 나머지 1수를 gcd하면 됨.
        else
        {
            result = gcd(distance, result);
        }
    }

    cout << result;

    return 0;
}