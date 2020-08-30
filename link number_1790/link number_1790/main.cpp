//
//  main.cpp
//  link number_1790
//
//  Created by 이원창 on 2020/08/28.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int n = 0;
int k = 0;
void dfs(int, int, int);
int main(int argc, const char * argv[]) {
    cin >> n >> k;

    int tmp = n;
    int nLen = 0;
    int totalLen = 0;

    while(true){
        if(tmp <= 0)
            break;
        tmp = tmp / 10;
        nLen++;
    }

    for(int i = 0; i < nLen; i++){
        totalLen += n;
        totalLen -= pow(10, i) - 1;
    }
    
    if(k > totalLen)
        cout << "-1\n";
    else{
        if(k < 10)
            cout << k << endl;
        else
            dfs(k, 10, 1);
    }
    
    return 0;
}
void dfs(int num, int cn, int level){
    if (num - (cn - cn / 10) * level > 0)
        dfs(num - (cn - cn / 10) * level, cn * 10, level + 1);
    int a = num / level;
    int b = num % level;
    cn /= 10;
    int tmp = cn + a - 1;
    int answer = tmp % 10;
    if (b > 0){
        tmp++;
        if (tmp > n)
            return;
        for (int i = 0; i < b; i++){
            answer = tmp / cn;
            tmp %= cn;
            cn /= 10;
        }
    }
    else if (tmp > n)
        return;

    cout << answer << endl;
}

