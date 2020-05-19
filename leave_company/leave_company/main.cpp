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
int* check;

int calculateSalary(int);
int main(int argc, const char * argv[]) {
    int salary = 0;
    int max = 0;
    
    scanf("%d", &n);
    t = new int[n];
    p = new int[n];
    check = new int[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &t[i], &p[i]);
        check[i] = 0;
    }
    for(int i = 0; i < n; i++){
        salary = calculateSalary(i);
        if(max < salary)
            max = salary;
    }
    printf("%d\n", max);
    
    return 0;
}
int calculateSalary(int num){
    int pay = 0;
    int next = num + t[num];
    pay = p[num];
    
    for(int i = 0; i < n; i++){
        if(check[i] == 0){
            check[i] = 1;
            pay += calculateSalary(num + i);
        }
    }
    
    if(next < n){
        pay += calculateSalary(num + 1);
        return pay;
    }
    else if(next == n)
        return pay;
    else
        return 0;
}

