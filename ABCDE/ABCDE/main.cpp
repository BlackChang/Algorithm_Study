//
//  main.cpp
//  ABCDE
//
//  Created by 이원창 on 2020/05/20.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0;
int m = 0;
int* man;
int main(int argc, const char * argv[]) {
    int temp = 0;
    int idx = 0;
    
    scanf("%d %d", &n, &m);
    vector<vector<int>> rel(n);
    man = new int[n];

    for(int i = 0; i < m; i++){
        scanf("%d %d", &idx, &temp);
        rel[idx].push_back(temp);
        rel[temp].push_back(idx);
    }
    
    return 0;
}
void check(int index){
    
}
