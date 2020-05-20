//
//  main.cpp
//  leave_company
//
//  Created by 이원창 on 2020/05/01.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int salary = 0;
int* t;
int* p;
void calculateSalary(int, int);
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    t = new int[n];
    p = new int[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d %d", &t[i], &p[i]);
    
    calculateSalary(0, 0);
    printf("%d\n", salary);
    
    return 0;
}
void calculateSalary(int index, int sum){
    if(index == n){
        salary = max(salary, sum);
        return;
    }
    if(index > n)
        return;
    calculateSalary(index + t[index], sum + p[index]);
    calculateSalary(index + 1, sum);
}

