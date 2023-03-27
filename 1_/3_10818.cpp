#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    //cin.tie(0);

    int N;
    int num;
    int min;
    int max;

    cin >> N;

    cin >> min; //가장 첫번째 원소를 min, max값으로 둔다
    max = min;

    for (int i = 1; i < N; i++)
    {
        cin >> num;
        if(num >= max){
            max = num;
        }
        else{
            if(num<=min){
                min = num;
            }
        }
    }

    cout << min << " " << max;
    

    return 0;   
}