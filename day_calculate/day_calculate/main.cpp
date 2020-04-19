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

int main(int argc, const char * argv[]) {
    int e = 0;
    int s = 0;
    int m = 0;
    int i = 0;
    int temp = 0;
    int year = 0;

    scanf("%d %d %d", &e, &s, &m);
    while(true){
        temp = i * 28 + s;
        if(((temp-e)%15 == 0) && ((temp-m)%19 == 0)){
            year = temp;
            break;
        }
        i += 1;
    }
    
    printf("%d\n", year);
    return 0;
}
