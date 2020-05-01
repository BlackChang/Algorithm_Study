//
//  main.cpp
//  next_permutation
//
//  Created by 이원창 on 2020/05/01.
//  Copyright © 2020 이원창. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int n = 0;
int len = 0;
int tmp = 0;
int* arr;
int* list;
int* check;
int* org;
void makeSequence(int);
using namespace std;
set<vector<int>> ans;
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    
    arr = new int[n];
    list = new int[n];
    check = new int[n];
    org = new int[n];
    
    for(int i = 0; i < n; i++){
        arr[i] = 0;
        check[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
        org[i] = list[i];
        check[i] = 0;
    }
    
    sort(list, list + n);
    
    makeSequence(0);
    for(auto temp : ans){
        if(len == temp.size()){
            for(int i = 0; i < temp.size(); i++)
                printf("%d ", temp[i]);
            printf("\n");
            tmp = 1;
        }
        len = 0;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] == org[i])
                len += 1;
        }
    }
    if(tmp != 1)
        printf("-1\n");
    return 0;
}
void makeSequence(int num){
    if(num == n){
        vector<int> temp;
        
        for(int i = 0; i < n; i++)
            temp.push_back(arr[i]);
        ans.insert(temp);
        temp.clear();
        
        return ;
    }
    for(int i = 0; i < n; i++){
        if(check[i] == 0){
            arr[num] = list[i];
            check[i] = 1;
            makeSequence(num + 1);
            check[i] = 0;
        }
    }
}


