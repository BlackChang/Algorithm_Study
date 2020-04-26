//
//  main.cpp
//  NnM_2
//
//  Created by 이원창 on 2020/04/25.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n = 0;
int m = 0;
int* arr;
void makeSequence(int);
int checkValid(int, int);
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    arr = new int[m];

    for(int i = 0; i < m; i++)
        arr[i] = 0;

//    for(int i = 0; i < n; i++)
        makeSequence(0);

    return 0;
}
void makeSequence(int num){
    for(int i = 1; i < n + 1; i++){
        if(checkValid(i, num)){
            arr[num] = i;
            makeSequence(num + 1);
        }
    }
    num = 0;
    for(int i = 0; i < m; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int checkValid(int check, int num){
    if(num == 0){
        if(arr[0] != check)
            return 1;
        else
            return 0;
    }
    else{
        for(int i = 0; i < num; i++){
            if(arr[i] == check)
                return 0;
        }
        return 1;
    }
}
