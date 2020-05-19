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
int main(int argc, const char * argv[]) {
    int n = 0;
    int* m;
    int state = 0;
    
    scanf("%d", &n);
    m = new int[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &m[i]);
    
    for(int i = 0; i < n; i++){
        if(m[i] == i + 1)
            state = 0;
        else{
            state = 1;
            break;
        }
    }
    for(int i = n - 1; i > 0; i--){
        if(m[n - 1] < m[i]){
            swap(m[i], m[n - 1]);
            sort(m + i + 1, m + n, greater<int>());
            break;
        }
    }
    if(state){
        for(int i = 0; i < n; i++)
            printf("%d ", m[i]);
        printf("\n");
    }
    else
        printf("-1\n");
    
    return 0;
}
