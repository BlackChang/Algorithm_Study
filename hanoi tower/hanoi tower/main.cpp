//
//  main.cpp
//  hanoi tower
//
//  Created by 이원창 on 2020/08/27.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;
int tmp = 0;
void hanoi(int, int, int, int);
int main(int argc, const char * argv[]) {
    int n = 0;
    long long ans = 1;
    
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        ans *= 2;
    }
    ans -= 1;
    
    cout << ans<< endl;
    hanoi(n, 1, 2, 3);

    return 0;
}
void hanoi(int n, int start, int tmp ,int end){
    if(n == 1){
        cout << "1 3" << endl;
        return;
    }
    else if(n == 2){
        cout << start << ' ' << tmp << endl;
        cout << start << ' ' << end << endl;
        cout << tmp << ' ' << end << endl;
        return;
    }

    hanoi(n - 1, start, end, tmp);
    cout << start << ' ' << end << endl;
    hanoi(n - 1, tmp, start, end);
}
