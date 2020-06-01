//
//  main.cpp
//  hide&seek3
//
//  Created by 이원창 on 2020/06/01.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 100001

using namespace std;
bool visit[MAX];
bool visit2[MAX];
int dist[MAX];
int m[] = {-1,1,2};
int n = 0;
int k = 0;
vector<int> ans;
void dfs(int);
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &k);
    dist[n] = 0;
    visit[n] = true;
    
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int next = 0;
        for(int i = 0; i < 3; i++){
            if(i != 2)
                next = cur + m[i];
            else
                next = cur * m[i];
            
            if(0 <= next && next < MAX){
                if(visit[next] == false){
                    visit[next] = true;
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
    printf("%d\n", dist[k]);
    dfs(n);
    return 0;
}
void dfs(int cur) {
    int next = 0;
    visit2[cur] = true;
    ans.push_back(cur);
    
    if (cur == k) {
        for (int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        if(i != 2)
            next = cur + m[i];
        else
            next = cur * m[i];

        if (dist[next] == dist[cur] + 1 && !visit2[next])
            dfs(next);
    }
    
    visit2[cur] = false;
    ans.pop_back();
}
