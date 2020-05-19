//
//  main.cpp
//  pre_permutation
//
//  Created by 이원창 on 2020/05/19.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int* m;
int findPermutation();
int main(int argc, const char * argv[]) {
    int idx = 0;
    int idx2 = 0;
    int max = 0;
    
    scanf("%d", &n);
    m = new int[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &m[i]);
    
    for(int i = n - 1; i > 0; i--){
        if(m[i] < m[i - 1]){
            idx = i - 1;
            break;
        }
    }
    for(int i = idx; i < n; i++){
        if((m[i] > max) && (m[idx] > m[i])){
            max = m[i];
            idx2 = i;
        }
    }
    swap(m[idx], m[idx2]);
    sort(m + idx + 1, m + n, greater<int>());

    if(idx2 != 0){
        for(int i = 0; i < n; i++)
            printf("%d ", m[i]);
        printf("\n");
    }
    else
        printf("-1\n");
    
    return 0;
}
