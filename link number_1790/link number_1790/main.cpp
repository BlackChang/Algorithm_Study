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
int dfs(int, int);
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
            cout << dfs(k, 1) << endl;
    }
    
    return 0;
}
int dfs(int k, int level){
    int answer = 0;
    int tmp = 9 * pow(10, level - 1) * level;
    int temp = pow(10, level - 1);
    int mod = k % level;
    if(k > tmp)
        dfs(k - tmp, level + 1);
    else{
        if(mod == 0)
            answer = ((k % temp) / level) - 1;
        else
            answer = ceil(k / (level * pow(10, level - mod)));
    }
    
    return answer;
}

