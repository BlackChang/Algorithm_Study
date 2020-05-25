//
//  main.cpp
//  link_start
//
//  Created by 이원창 on 2020/05/25.
//  Copyright © 2020 이원창. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n = 0;
int ans = INT_MAX;
int* arr;
int** s;
int check[20];
vector<int> v1;
vector<int> v2;
void makeSequence(int);
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    s = new int* [n];
    arr = new int[n/2];
    
    for(int i = 0; i < n; i++)
        s[i] = new int[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);
    }
    makeSequence(0);
    printf("%d\n", ans);
    return 0;
}
void makeSequence(int num){
    if(num == n/2){
        int sum1 = 0;
        int sum2 = 0;
        int temp = 0;
        v1.clear();
        v2.clear();
        for(int i = 0; i < n; i++){
            if(check[i])
                v1.push_back(i);
            else
                v2.push_back(i);
        }
        for(int i = 0; i < n/2; i++){
            for(int j = i; j < n/2; j++){
                sum1 += s[v1[i]][v1[j]] + s[v1[j]][v1[i]];
                sum2 += s[v2[i]][v2[j]] + s[v2[j]][v2[i]];
            }
        }
        temp = abs(sum1 - sum2);
        if(temp < ans)
            ans = temp;
    }
    else if(num == 0){
        for(int i = 1; i <= n; i++){
            if(check[i - 1] == 0){
                arr[num] = i;
                check[i - 1] = 1;
                makeSequence(num + 1);
                arr[num] = 0;
                check[i - 1] = 0;
            }
        }
    }
    else{
        for(int i = 1; i <= n; i++){
            if((check[i - 1] == 0) && (arr[num - 1] < i)){
                arr[num] = i;
                check[i - 1] = 1;
                makeSequence(num + 1);
                arr[num] = 0;
                check[i - 1] = 0;
            }
        }
    }
}
