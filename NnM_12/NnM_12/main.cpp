//
//  main.cpp
//  NnM_12
//
//  Created by 이원창 on 2020/04/28.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int n = 0;
int m = 0;
int* arr;
int* list;
void makeSequence(int);

using namespace std;
set<vector<int>> ans;
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    
    arr = new int[m];
    list = new int[n];
    
    for(int i = 0; i < n; i++)
        arr[i] = 0;
    
    for(int i = 0; i < n; i++)
        scanf("%d", &list[i]);
    
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
    else if(num == 0){
        for(int i = 0; i < n; i++){
            arr[num] = list[i];
            makeSequence(num + 1);
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(arr[num - 1] <= list[i]){
                arr[num] = list[i];
                makeSequence(num + 1);
            }
        }
    }
}


