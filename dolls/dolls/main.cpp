//
//  main.cpp
//  dolls
//
//  Created by 이원창 on 2020/04/29.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int* doll;
int main(int argc, const char * argv[]) {
    int n = 0;
    int k = 0;
    long double sum = 0;
    long double avg = 0;
    long double v = 0;
    long double stdv = 0;
    long double min = 0;
    long double temp = 0;
    
    scanf("%d %d", &n, &k);
    doll = new int[n];
    min = 10000000;
    
    for(int i = 0; i < n; i++)
        scanf("%d", &doll[i]);
        
    for(int i = 0; i < n - k + 1; i++){
        temp = k;
        while(i + temp <= n){
            sum = 0;
            avg = 0;
            v = 0;
            stdv = 0;
            for(int j = i; j < i + temp; j++)
                sum += doll[j];

            avg = (sum / temp);

            for(int j = i; j < i + temp; j++)
                v += (long double)(pow((avg - doll[j]), 2));
            
            v /= temp;
            stdv = (long double)sqrt(v);
            if(stdv < min)
                min = stdv;
            
            temp += 1;
        }
    }
    printf("%Lf\n", min);
    
    return 0;
}
