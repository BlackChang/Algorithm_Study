//
//  main.cpp
//  link_number
//
//  Created by 이원창 on 2020/04/23.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, const char * argv[]) {
    int num;
    int sum = 0;
    
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        if(0 < i && i < 10)
            sum += 1;
        else if(10 <= i && i < 100)
            sum += 2;
        else if(100 <= i && i < 1000)
            sum += 3;
        else if(1000 <= i && i < 10000)
            sum += 4;
        else if(10000 <= i && i < 100000)
            sum += 5;
        else if(100000 <= i && i < 1000000)
            sum += 6;
        else if(100000 <= i && i < 10000000)
            sum += 7;
        else if(1000000 <= i && i < 100000000)
            sum += 8;
        else
            sum += 9;
    }
    printf("%d\n", sum);
    return 0;
}
