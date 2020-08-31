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
int main(int argc, const char * argv[]) {
    int n = 0;
    int k = 0;
    int check = 1;
    long long int sum = 0;

    cin >> n >> k;
    
    int l = 1;
    int r = n;
    int ans = 0;
    while(check <= n){
        sum += (n - check + 1);
        check *= 10;
    }
    if(sum < k){
        cout << "-1\n";
        return 0;
    }
    while(l <= r){
        int m = (l + r) / 2;
        sum = 0;
        check = 1;
        while(check <= m){
            sum += (m - check + 1);
            check *= 10;
        }
        if(sum >= k){
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    
    check = 1;
    sum = 0;
    while(check <= ans){
        sum += (ans - check + 1);
        check *= 10;
    }
    
    string s = to_string(ans);
    cout << s[s.size() - (sum - k) - 1] << endl;
    
    return 0;
}

