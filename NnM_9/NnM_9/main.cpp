//
//  main.cpp
//  NnM_9
//
//  Created by 이원창 on 2020/04/27.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int n = 0;
int m = 0;
int len = 0;
int tmp = 0;
int* arr;
int* list;
int* check;
int check_num[10000] = {0, };

void makeSequence(int);
using namespace std;
set<vector<int>> ans;
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    
    arr = new int[m];
    list = new int[n];
    check = new int[n];
    
    for(int i = 0; i < n; i++){
        arr[i] = 0;
        check[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
        check[i] = 0;
    }
    
    sort(list, list + n);
    
    makeSequence(0);
    for(auto temp : ans){
        for(int i = 0; i < temp.size(); i++)
            printf("%d ", temp[i]);
        printf("\n");
    }
    return 0;
}
void makeSequence(int num){
    if(num == m){
        vector<int> temp;
        
        for(int i = 0; i < m; i++)
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


