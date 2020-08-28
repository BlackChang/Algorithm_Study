//
//  main.cpp
//  hanoi tower
//
//  Created by 이원창 on 2020/08/27.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
using namespace std;
void hanoi(int, int, int, int);
int main(int argc, const char * argv[]) {
    int n = 0;
    long long ans = 1;
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        ans *= 2;
    }
    ans -= 1;
    
    cout << ans << "\n";
    hanoi(n, 1, 2, 3);

    return 0;
}
void hanoi(int n, int start, int mid ,int end){
    if(n == 1)
        cout << start << " " << end << "\n";
    else {
        hanoi(n - 1, start, end, mid);
        hanoi(1, start, mid, end);
        hanoi(n - 1, mid, start, end);
    }
}
