#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int num;
    int max = 0;
    int max_key;
    map<int, int> appearMap;

    for(int i=0;i<10;i++){
        cin >> num;
        
        //찾지 못한 경우
        if(appearMap.find(num) == appearMap.end()){
            appearMap.insert({num, 1});
        }
        else{
            appearMap[num] += 1;
        }

        sum += num;
    }

    //map<int,int>::iterator == auto
    for(auto iter = appearMap.begin(); iter!=appearMap.end(); iter++){
        if(max < iter->second){
            max = iter->second;
            max_key = iter->first;
        }
    }

    cout << sum/10 << "\n" << max_key;

    return 0;   
}