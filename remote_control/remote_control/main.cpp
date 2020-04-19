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

int main(int argc, const char * argv[]) {
    int ch = 0;
    int num = 0;
    int* btn;
    int temp = 0;
    
    scanf("%d", &ch);
    scanf("%d", &num);
    btn = new int[num];
    
    for(int i = 0; i < num; i++)
        scanf("%d", &btn[i]);

    for(int i = 10; i < 100000; i *= 10 ){
        temp = ch % 10;
        
    }
    return 0;
}
