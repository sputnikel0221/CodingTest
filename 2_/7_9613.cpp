#include <iostream>
#include <vector>
using namespace std;

int GCD(int, int);

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int N;
    cin >> N;

    int T;
    int num;

    // N개의 줄을 받음
    for (int i = 0; i < N; i++)
    {
        vector<int> arr;
        long sum = 0;
        // 줄마다 T개의 원소들을 받음
        cin >> T;

        if(T==1){
            cout << sum << '\n';
            break;
        }

        for (int t = 0; t < T; t++)
        {
            cin >> num;
            arr.push_back(num);
        }

        // Debug 원소 출력
        // for (int t = 0; t < T; t++)
        // {
        //     cout << arr.at(t) << ", ";
        // }


        for (int q = 0; q < T - 1; q++)
        {
            for (int p = q+1; p < T; p++)
            {
                //debug
                //cout << "{q : " << q << "    p: " << p << "} \n"; 
                if (arr.at(q) >= arr.at(p))
                {
                    //debug
                    //cout << "+ "<< GCD(arr.at(q),arr.at(p)) <<'\n';
                    sum += GCD(arr.at(q),arr.at(p));
                }
                else
                {
                    //debug
                    //cout << "+ "<< GCD(arr.at(p),arr.at(q)) <<'\n';
                    sum += GCD(arr.at(p),arr.at(q));
                }
            }
        }
        cout << sum << '\n';
    }

    return 0;
}

// 유클리드 호제법
int GCD(int a, int b)
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