//
//  main.cpp
//  NnM_11
//
//  Created by 이원창 on 2020/04/27.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n = 0;
int m = 0;
int tmp = 0;
int* arr;
int* list;
int* temp;
void makeSequence(int);
int checkValid();
using namespace std;

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    arr = new int[m];
    list = new int[n];
    temp = new int[m];
    for(int i = 0; i < m; i++)
        arr[i] = 0;
    
    for(int i = 0; i < n; i++)
        scanf("%d", &list[i]);
    
    sort(list, list + n);
    makeSequence(0);
    
    return 0;
}
void makeSequence(int num){
    if(num == m){
        if(checkValid()){
            for(int i = 0; i < m; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        for(int i = 0; i < m; i++)
            temp[i] = arr[i];
    }
    else if(num == 0){
        for(int i = 0; i < n; i++){
            if(tmp != list[i]){
                arr[num] = list[i];
                tmp = list[i];
                makeSequence(num + 1);
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
                arr[num] = list[i];
                makeSequence(num + 1);
        }
    }
}
int checkValid(){
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(temp[i] == arr[i])
            cnt += 1;
    }
    if(cnt == m)
        return 0;
    else
        return 1;
}

