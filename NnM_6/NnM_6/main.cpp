//
//  main.cpp
//  NnM_6
//
//  Created by 이원창 on 2020/04/27.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n = 0;
int m = 0;
int* arr;
int* list;
int* check;
void makeSequence(int);
using namespace std;

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    arr = new int[m];
    list = new int[n];
    check = new int[n];
    
    for(int i = 0; i < m; i++)
        arr[i] = 0;
    
    for(int i = 0; i < n; i++)
        check[i] = 0;
    
    for(int i = 0; i < n; i++)
        scanf("%d", &list[i]);
    
    sort(list, list + n);
    
    makeSequence(0);
    
    return 0;
}
void makeSequence(int num){
    if(num == m){
        for(int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else if(num == 0){
        for(int i = 0; i < n; i++){
            if(check[i] == 0){
                arr[num] = list[i];
                check[i] = 1;
                makeSequence(num + 1);
                check[i] = 0;
            }
        }
        
    }
    else{
        for(int i = 0; i < n; i++){
            if((check[i] == 0) && (arr[num - 1] < list[i])){
                arr[num] = list[i];
                check[i] = 1;
                makeSequence(num + 1);
                check[i] = 0;
            }
        }
    }
}

