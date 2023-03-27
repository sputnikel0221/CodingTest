#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<char, int> strmap;
    int max = 0;
    char max_char;
    int same_count = 0; //같은 빈도수 체크

    string s_input;
    cin >> s_input;

    for(int i=0;i<s_input.length();i++){
        if('A' <= s_input[i] && s_input[i] <= 'Z'){
            if(strmap.find(s_input[i])==strmap.end()){
                strmap.insert({s_input[i], 1});
            }
            else{
                strmap[s_input[i]] += 1;
            }
        }
        else if('a' <= s_input[i] && s_input[i] <= 'z'){
            if(strmap.find(s_input[i]-32)==strmap.end()){
                strmap.insert({s_input[i]-32, 1});
            }
            else{
                strmap[s_input[i]-32] += 1;
            }
        }
    }

    map<char, int>::iterator iter;
    for(iter = strmap.begin(); iter!=strmap.end(); iter++){
        if(max <= iter->second){
            max = iter->second;
            max_char = iter->first;
        }
    }

    for(iter = strmap.begin(); iter!=strmap.end(); iter++){
        if(max == iter->second){
            same_count++;
        }
    }

    if(2 <= same_count){
        cout << '?';
    } 
    else{
        cout<< max_char;
    }

    return 0;   
}