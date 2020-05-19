//
//  main.cpp
//  next_permutation
//
//  Created by 이원창 on 2020/05/01.
//  Copyright © 2020 이원창. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int n = 0;
int len = 0;
int tmp = 0;
int* arr;
int* list;
int* check;
int* org;
void makeSequence(int);
using namespace std;
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    
    arr = new int[n];
    list = new int[n];
    check = new int[n];
    org = new int[n];
    
    for(int i = 0; i < n; i++){
        arr[i] = 0;
        check[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
        org[i] = list[i];
    }
    
    sort(list, list + n);
    makeSequence(0);
    
    if(tmp != 1)
        printf("-1\n");
    return 0;
}
void makeSequence(int num){
    if(num == n){
//        if(len == n){
            for(int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            tmp = 1;
//        }
        len = 0;
//        for(int i = 0; i < n; i++){
//            if(arr[i] == org[i])
//                len += 1;
//        }
        
        return ;
    }
    else if(num == 0){
        for(int i = org[num] - 1; i < n; i++){
            if(check[i] == 0){
                arr[num] = list[i];
                check[i] = 1;
                makeSequence(num + 1);
                check[i] = 0;
            }
        }
    }
    else{
        for(int i = org[num] - 1; i < n; i++){
            if(check[i] == 0){
                arr[num] = list[i];
                check[i] = 1;
                makeSequence(num + 1);
                check[i] = 0;
            }
        }
    }
}

