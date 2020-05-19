//
//  main.cpp
//  next_permutation
//
//  Created by 이원창 on 2020/05/01.
//  Copyright © 2020 이원창. All rights reserved.
//
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int* m;
int main(int argc, const char * argv[]) {
    int idx = 0;
    int idx2 = 0;
    
    scanf("%d", &n);
    m = new int[n];
    int min = n + 1;
    
    for(int i = 0; i < n; i++)
        scanf("%d", &m[i]);
    
    for(int i = n - 1; i > 0; i--){
        if(m[i] > m[i - 1]){
            idx = i - 1;
            break;
        }
    }
    for(int i = idx + 1; i < n; i++){
        if((m[i] < min) && (m[idx] < m[i])){
            min = m[i];
            idx2 = i;
        }
    }
    swap(m[idx], m[idx2]);
    sort(m + idx + 1, m + n);
    
    if(idx2 != 0){
        for(int i = 0; i < n; i++)
            printf("%d ", m[i]);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}

