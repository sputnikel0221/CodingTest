#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int var_mode;
    string input;
    string camel, snake, pascal;

    cin >> var_mode >> input;

    switch (var_mode)
    {
    // camel
    case 1:
        camel = input;

        //snake
        for(int i=0; i<input.size();i++){
            if('a' <= input[i] && input[i]<= 'z'){
                snake+=input[i];
            }
            else{
                snake+='_';
                snake+= input[i]+32;
            }
        }

        //pascal
        pascal = input;
        pascal[0] = pascal[0]-32;
        break;

    // snake
    case 2:
        snake = input;

        //camel
        for(int i=0; i<input.size();i++){
            if('a' <= input[i] && input[i]<= 'z'){
                camel+=input[i];
            }
            else{
                camel+= input[i+1]-32;
                i=i+1;
            }
        }

        //pascal
        pascal = camel;
        pascal[0] = pascal[0]-32;
        break;

    // pascal
    case 3:
        pascal = input;

        //camel
        camel = pascal;
        camel[0] = camel[0] + 32;

        //snake
        for(int i=0; i<input.size();i++){
            if('a' <= input[i] && input[i]<= 'z'){
                snake+=input[i];
            }
            else{
                if(i!=0){
                    snake+= '_';
                }
                snake+= input[i]+32;
            }
        }

        break;
    }
    cout << camel << "\n" << snake << "\n" << pascal;

    return 0;   
}