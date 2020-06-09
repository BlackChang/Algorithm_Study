//
//  main.cpp
//  radius_of_tree
//
//  Created by 이원창 on 2020/06/09.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n = 0;
int ans = 0;
int temp = 0;
int root = 0;
bool* visit;
vector<pair<int, int>>* v;
void dfs(int);
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    visit = new bool[n + 1];
    v = new vector<pair<int, int>>[n + 1];
    
    for(int i = 0; i < n; i++){
        int idx = 0;
        int p = 0;
        int d = 0;
        
        scanf("%d", &idx);
        scanf("%d", &p);
        
        while(p != -1){
            scanf("%d", &d);
            v[idx].push_back(make_pair(p, d));
            scanf("%d", &p);
        }
    }
    
    dfs(1);
    ans = 0;
    for(int i = 0; i <= n; i++)
        visit[i] = false;
    dfs(root);
    printf("%d\n", ans);
    
    return 0;
}
void dfs(int idx){
    for(int i = 0; i < v[idx].size(); i++){
        int next = v[idx][i].first;
        if(!visit[next]){
            visit[next] = true;
            temp += v[idx][i].second;
            dfs(next);
            if(ans < temp){
                ans = temp;
                root = next;
            }
            visit[next] = false;
            temp -= v[idx][i].second;
        }
    }
}
