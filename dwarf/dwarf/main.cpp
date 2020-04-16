//
//  main.cpp
//  seven_dwarf
//
//  Created by 이원창 on 2020/04/08.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int sum = 0;
    int i = 0;
    int temp = 0;
    int idx1 = 0;
    int idx2 = 0;
    int dwarf[9];
    
    while(i < 9){
        scanf("%d", &temp);
        if(temp < 100){
            dwarf[i] = temp;
            sum += dwarf[i];
            i++;
        }
    }
    sum -= 100;
    sort(dwarf, dwarf+9);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(i == j)
                continue;
            else{
                if(dwarf[i] + dwarf[j] == sum){
                    idx1 = i;
                    idx2 = j;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < 9; i++){
        if(i == idx1 || i == idx2)
            continue;
        else
            printf("%d\n", dwarf[i]);
    }

    return 0;
}
