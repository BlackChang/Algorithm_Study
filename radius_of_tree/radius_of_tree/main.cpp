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
    printf("%d\n", ans);
    return 0;
}
void dfs(int idx){
    for(int i = 0; i < v[idx].size(); i++){
        if(!visit[v[idx][i].first]){
            visit[v[idx][i].first] = true;
            temp += v[idx][i].second;
            if(ans < temp)
                ans = temp;
            dfs(v[idx][i].first);
            visit[v[idx][i].first] = false;
            temp -= v[idx][i].second;
        }
    }
}
