#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int odd_sum = 0;
    int min=99; //주어지는 자연수는 100보다 작다.

    for (int i = 0; i < 7; i++)
    {
        cin >> num;
        if (num % 2 == 1)
        {
            if (num <= min)
            {
                min = num;
            }
            odd_sum += num;
        }
    }
    if(odd_sum > 0){
        cout << odd_sum << "\n"
         << min;
    }
    else{
        cout << -1;
    }
    

    return 0;
}