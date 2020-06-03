//
//  main.cpp
//  inequality
//
//  Created by 이원창 on 2020/06/02.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0;
bool visit[10];
bool suc = false;
vector<char> v;
vector<int> ans;
void dfsMin(int);
void dfsMax(int);
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    getchar();
    v = vector<char>(n);
    
    for(int i = 0; i < n; i++){
        scanf("%c", &v[i]);
        getchar();
    }
    
    for(int i = 9; i >= 0; i--){
        ans.push_back(i);
        visit[i] = true;
        dfsMax(0);
        ans.pop_back();
        visit[i] = false;
        if(suc)
            break;
    }

    suc = false;
    for(int i = 0; i < 10; i++){
        ans.push_back(i);
        visit[i] = true;
        dfsMin(0);
        ans.pop_back();
        visit[i] = false;
        if(suc)
            break;
    }
    
    return 0;
}
void dfsMin(int idx){
    if(idx == n){
        for(int i = 0; i < ans.size(); i++)
            printf("%d", ans[i]);
        printf("\n");
        suc = true;
        return ;
    }
    
    for(int i = 0; i < 10; i++){
        if(visit[i] == false){
            if(v[idx] == '>'){
                if(ans[idx] > i){
                    ans.push_back(i);
                    visit[i] = true;
                    dfsMin(idx + 1);
                    visit[i] = false;
                    ans.pop_back();
                }
            }
            else if(v[idx] == '<'){
                if(ans[idx] < i){
                    ans.push_back(i);
                    visit[i] = true;
                    dfsMin(idx + 1);
                    visit[i] = false;
                    ans.pop_back();
                }
            }
        }
        if(suc)
            break;
    }
}
void dfsMax(int idx){
    if(idx == n){
        for(int i = 0; i < ans.size(); i++)
            printf("%d", ans[i]);
        printf("\n");
        suc = true;
        return ;
    }
    
    for(int i = 9; i >= 0; i--){
        if(visit[i] == false){
            if(v[idx] == '>'){
                if(ans[idx] > i){
                    ans.push_back(i);
                    visit[i] = true;
                    dfsMax(idx + 1);
                    visit[i] = false;
                    ans.pop_back();
                }
            }
            else if(v[idx] == '<'){
                if(ans[idx] < i){
                    ans.push_back(i);
                    visit[i] = true;
                    dfsMax(idx + 1);
                    visit[i] = false;
                    ans.pop_back();
                }
            }
        }
        if(suc)
            break;
    }
}
