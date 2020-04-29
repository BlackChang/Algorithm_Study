//
//  main.cpp
//  prize_hunter
//
//  Created by 이원창 on 2020/04/29.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int calculatePrize(int, int);
int main(int argc, const char * argv[]) {
    int t = 0;
    int a = 0;
    int b = 0;
    int* prize;
    
    scanf("%d", &t);
    prize = new int[t];

    for(int i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        prize[i] = calculatePrize(a, b);
    }
    
    for(int i = 0; i < t; i++)
        printf("%d\n", prize[i]);
    
    return 0;
}
int calculatePrize(int a, int b){
    int sum = 0;
    if(a == 1)
        sum += 500;
    else if(a > 1 && a < 4)
        sum += 300;
    else if(a > 3 && a < 7)
        sum += 200;
    else if(a > 6 && a < 11)
        sum += 50;
    else if(a > 10 && a < 16)
        sum += 30;
    else if(a > 15 && a < 22)
        sum += 10;
    else
        sum += 0;
    
    if(b == 1)
        sum += 512;
    else if(b > 1 && b < 4)
        sum += 256;
    else if(b > 3 && b < 8)
        sum += 128;
    else if(b > 7 && b < 16)
        sum += 64;
    else if(b > 15 && b < 32)
        sum += 32;
    else
        sum += 0;
    
    sum *= 10000;
    
    return sum;
}
