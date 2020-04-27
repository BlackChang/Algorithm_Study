//
//  main.cpp
//  NnM_1
//
//  Created by 이원창 on 2020/04/25.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n = 0;
int m = 0;
int* arr;
int* check;
void makeSequence(int);
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    arr = new int[m];
    check = new int[m];
    
    for(int i = 0; i < m; i++){
        arr[i] = 0;
        check[i] = 0;
    }
    
    makeSequence(0);
    return 0;
}
void makeSequence(int num){
    if(num == m){
        for(int i = 0; i < m; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            arr[num] = i;
            check[i] = 1;
            makeSequence(num + 1);
            arr[num] = 0;
            check[i] = 0;
        }
    }
}
