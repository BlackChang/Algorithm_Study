//
//  main.cpp
//  plus_123
//
//  Created by 이원창 on 2020/04/23.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int recursive(int);
int main(int argc, const char * argv[]) {
    int* arr;
    int* num;
    int t;

    scanf("%d", &t);
    arr = new int[t];
    num = new int[t];
    for(int i = 0; i < t; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < t; i++)
        num[i] = recursive(arr[i]);

    for(int i = 0; i < t; i++)
        printf("%d\n", num[i]);
    return 0;
}
int recursive(int n){
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else if(n == 3)
        return 4;
    else
        return recursive(n-1) + recursive(n-2) + recursive(n-3);
}
