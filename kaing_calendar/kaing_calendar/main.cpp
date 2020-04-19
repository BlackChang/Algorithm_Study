//
//  main.cpp
//  day_calculate
//
//  Created by 이원창 on 2020/04/19.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
int gcd(int, int);
int lcm(int, int);
int main(int argc, const char * argv[]) {
    int t = 0;
    int x = 0;
    int y = 0;
    int m = 0;
    int n = 0;
    int roop = 0;
    int max = 0;
    int min = 0;
    int max_val = 0;
    int min_val = 0;
    int max_year = 0;
    int temp = 0;
    int* year = 0;

    scanf("%d", &t);
    year = new int[t];
    for(int i = 0; i < t; i++){
        scanf("%d %d %d %d", &m, &n, &x, &y);
        if(m > n){
            max = m;
            max_val = x;
            min = n;
            min_val = y;
        }
        else if(m <= n){
            max = n;
            max_val = y;
            min = m;
            min_val = x;
        }
        
        max_year = lcm(max, min);
        roop = 0;
        
        while(true){
            temp = roop * max + max_val;
            if((temp-min_val) % min == 0){
                year[i] = temp;
                break;
            }
            else if(temp > max_year){
                year[i] = -1;
                break;
            }
            roop += 1;
        }
    }
    for(int i = 0; i < t; i++)
        printf("%d\n", year[i]);
    
    return 0;
}
int gcd(int a, int b){
    int c;
    while (b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
