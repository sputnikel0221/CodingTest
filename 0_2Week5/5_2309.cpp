#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9];

    int result = 0;
    for(int i=0;i<9;i++)
    {
        cin >> arr[i];
        result += arr[i];
    }

    int a=0, b=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(result - (arr[i]+arr[j]) == 100)
            {
                a = i;
                b = j;
                break;
            }
        }

        if(a!=b)
        {
            break;
        }
    }

    set<int> s;
    for(int i=0;i<9;i++)
    {
        if(i==a || i==b)
        {
            continue;
        }
        else
        {
            s.insert(arr[i]);
        }
    }


    for(auto a : s)
    {
        cout << a << "\n";
    }

    

    return 0;   
}