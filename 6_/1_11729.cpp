#include <iostream>
#include <math.h>
using namespace std;


void Hanoi(int, int, int, int);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int K = pow(2, N) -1;
    cout << K << "\n";

    Hanoi(N, 1, 2, 3);

    return 0;   
}

// n개의 판을 from에서 to로 옮긴다. 필요시 by사용.
void Hanoi(int n, int from, int by, int to)
{
    if(n==1)
    {
        cout << from << " " << to << "\n";
    }
    else
    {
        Hanoi(n-1, from, to, by);
        cout << from << " " << to << "\n";
        Hanoi(n-1, by, from, to);
    }
}