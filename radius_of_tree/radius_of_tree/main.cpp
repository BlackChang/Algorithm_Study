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
int** dis;
bool* visit;
vector<int>* v;
void dfs(int);
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    visit = new bool[n + 1];
    v = new vector<int>[n + 1];
    dis = new int*[n + 1];
    
    for(int i = 0; i <= n; i++)
        dis[i] = new int[n + 1];
    
    for(int i = 0; i < n; i++){
        int idx = 0;
        int p = 0;
        int d = 0;
        
        scanf("%d", &idx);
        scanf("%d", &p);
        
        while(p != -1){
            scanf("%d", &d);
            v[idx].push_back(p);
            dis[idx][p] = d;
            dis[p][idx] = d;
            scanf("%d", &p);
        }
    }
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            printf("%d ", dis[i][j]);
//        }
//        printf("\n");
//    }
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j < v[i].size(); j++){
//            printf("%d ", v[i][j]);
//        }
//        printf("\n");
//    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
void dfs(int idx){
    for(int i = 0; i < v[idx].size(); i++){
        if(!visit[v[idx][i]]){
            visit[v[idx][i]] = true;
            temp += dis[idx][v[idx][i]];
            if(ans < temp)
                ans = temp;
            dfs(v[idx][i]);
            visit[v[idx][i]] = false;
            temp -= dis[idx][v[idx][i]];
        }
    }
}
