//
//  main.cpp
//  remote_control
//
//  Created by 이원창 on 2020/04/19.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

int num = 0;
int* btn;
int isIn(int);
int remote(int);
int getLen(int);
int main(int argc, const char * argv[]) {
    int target = 0;
    int tmpLen = 0;
    int temp = 0;
    int min = 500001;
    
    scanf("%d", &target);
    scanf("%d", &num);
    btn = new int[num];
    
    for(int i = 0; i < num; i++)
        scanf("%d", &btn[i]);
    
    int idx = 0;
    for(int i = 0; i < 1000000; i++){
        if(remote(i)){
            tmpLen = getLen(i);
            temp = tmpLen + abs(target - i);
        }
        else
            temp = abs(target - 100);
        
        if(temp < min){
            min = temp;
            idx = i;
        }
    }
    printf("%d %d\n", min, idx);
    
    return 0;
}
int remote(int target){
    int test = 0;
    while(target > 0){
        test = target % 10;
        for(int j = 0; j < num; j++){
            if(test == btn[j])
                return 0;
        }
        target /= 10;
    }
    return 1;
}
int getLen(int target){
    int temp = 0;
    int len = 0;
    for(int i = 1;; i *= 10){
        temp = target/i;
        if(temp < 1)
            break;
        len += 1;
    }

    return len;
}
