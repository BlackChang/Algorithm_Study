//
//  main.cpp
//  leave_company
//
//  Created by 이원창 on 2020/05/01.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n = 0;
int* t;
int* p;

int calculateSalary(int);
int main(int argc, const char * argv[]) {
    int salary = 0;
    int max = 0;
    
    scanf("%d", &n);
    t = new int[n];
    p = new int[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d %d", &t[i], &p[i]);
    
    for(int i = 0; i < n; i++){
        salary = calculateSalary(i);
        if(max < salary)
            max = salary;
    }
    printf("%d\n", max);
    
    return 0;
}
int calculateSalary(int num){
    int temp = t[num];
    int sum = 0;
//    int tempSalary = 0;
    
    sum = p[num];
    if(num + temp < n){
        sum += calculateSalary(num + 1);
        return sum;
    }
    else if(num + temp == n)
        return sum;
    else
        return 0;
}

