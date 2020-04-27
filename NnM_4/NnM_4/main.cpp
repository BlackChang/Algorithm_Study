//
//  main.cpp
//  NnM_4
//
//  Created by 이원창 on 2020/04/27.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n = 0;
int m = 0;
int* arr;
int check[9];
void makeSequence(int);
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    arr = new int[m];
    
    for(int i = 0; i < m; i++)
        arr[i] = 0;
    
    for(int i = 0; i < 9; i++)
        check[i] = 0;
    
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
    else if(num == 0){
        for(int i = 1; i <= n; i++){
            if(check[i - 1] == 0){
                arr[num] = i;
                makeSequence(num + 1);
            }
        }
    }
    else{
        for(int i = 1; i <= n; i++){
            if((check[i - 1] == 0) && (arr[num - 1] <= i)){
                arr[num] = i;
                makeSequence(num + 1);
            }
        }
    }
}
