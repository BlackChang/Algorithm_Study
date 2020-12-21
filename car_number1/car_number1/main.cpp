//
//  main.cpp
//  car_number1
//
//  Created by 이원창 on 2020/12/21.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string str = "";
    int ans = 1;
    cin >> str;
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'c'){
            if(i == 0)
                ans *= 26;
            else{
                if(str[i-1] == 'c')
                    ans *= 25;
                else
                    ans *= 26;
            }
        }
        else {
            if(i == 0)
                ans *= 10;
            else{
                if(str[i - 1] == 'd')
                    ans *= 9;
                else
                    ans *= 10;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

