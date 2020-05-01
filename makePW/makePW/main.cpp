//
//  main.cpp
//  makePW
//
//  Created by 이원창 on 2020/04/30.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int l = 0;
int c = 0;
int valid1 = 0;
int valid2 = 0;
char* arr;
char* list;
int* check;

void makePW(int);
using namespace std;
set<vector<int>> ans;
int main(int argc, const char * argv[]) {
    scanf("%d %d", &l, &c);
    getchar();
    
    arr = new char[l];
    list = new char[c];
    check = new int[c];
    
    for(int i = 0; i < c; i++)
        arr[i] = 'a';
    
    for(int i = 0; i < c; i++){
        scanf("%c", &list[i]);
        getchar();
        check[i] = 0;
    }
    
    sort(list, list + c);
    
    makePW(0);
    for(auto temp : ans){
        valid1 = 0;
        valid2 = 0;
        for(int i = 0; i < temp.size(); i++){
            if((temp[i] == 'a') || (temp[i] == 'i') || (temp[i] == 'e') || (temp[i] == 'o') || (temp[i] == 'u')){
                valid1 = 1;
            }
            else
                valid2 += 1;
        }
        if((valid1 == 1) && (valid2 >= 2)){
            for(int i = 0; i < temp.size(); i++)
                printf("%c", temp[i]);
            printf("\n");
        }
    }
    return 0;
}
void makePW(int num){
    if(num == l){
        vector<int> temp;
        
        for(int i = 0; i < l; i++)
            temp.push_back(arr[i]);
        ans.insert(temp);
        temp.clear();
        
        return ;
    }
    else if(num == 0){
        for(int i = 0; i < c; i++){
            if(check[i] == 0){
                arr[num] = list[i];
                check[i] = 1;
                makePW(num + 1);
                check[i] = 0;
            }
        }
    }
    else{
        for(int i = 0; i < c; i++){
            if((check[i] == 0) && (arr[num - 1] < list[i])){
                arr[num] = list[i];
                check[i] = 1;
                makePW(num + 1);
                check[i] = 0;
            }
        }
    }
}

