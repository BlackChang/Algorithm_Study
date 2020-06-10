//
//  main.cpp
//  radius_of_tree_1967
//
//  Created by 이원창 on 2020/06/09.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n = 0;
long long int ans = 0;
int root = 0;
bool* visit;
vector<pair<int, int>>* v;
void dfs(int, long long int);
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    visit = new bool[n + 1];
    v = new vector<pair<int, int>>[n + 1];
    
    for(int i = 0; i < n - 1; i++){
        int idx = 0;
        int p = 0;
        int d = 0;
        
        scanf("%d %d %d", &idx, &p, &d);
        v[idx].push_back(make_pair(p, d));
        v[p].push_back(make_pair(idx, d));
    }
    
    dfs(1, 0);
    ans = 0;
    dfs(root, 0);
    printf("%lld\n", ans);
    
    return 0;
}
void dfs(int idx, long long int len){
    if(visit[idx])
        return;
    
    visit[idx] = true;
    for(int i = 0; i < v[idx].size(); i++){
        int next = v[idx][i].first;
        if(!visit[next]){
            long long int tmp = len + v[idx][i].second;
            dfs(next, tmp);
            if(ans < tmp){
                ans = tmp;
                root = next;
            }
        }
    }
    visit[idx] = false;
}

