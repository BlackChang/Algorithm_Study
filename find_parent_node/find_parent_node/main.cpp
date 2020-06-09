//
//  main.cpp
//  find_parent_node
//
//  Created by 이원창 on 2020/06/09.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n = 0;
int* par;
bool* visit;
vector<int> *v;
void dfs(int);
int main(int argc, const char * argv[]){
    int tmp1 = 0;
    int tmp2 = 0;
    
    scanf("%d", &n);
    par = new int[n + 1];
    visit = new bool[n + 1];
    v = new vector<int>[n + 1];
    
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &tmp1, &tmp2);
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    
    dfs(1);
    for(int i = 2; i <= n; i++)
        printf("%d\n", par[i]);
    
    return 0;
}
void dfs(int idx){
    visit[idx] = true;
    if((int)(v[idx].size()) == 1){
        if(idx != 1){
            par[idx] = v[idx].front();
            return;
        }
        else
            dfs(v[idx].front());
    }
    else{
        for(int i = 0; i < v[idx].size(); i++){
            if(visit[v[idx][i]])
                par[idx] = v[idx][i];
            else
                dfs(v[idx][i]);
        }
    }
}
