//
//  main.cpp
//  subway_line2
//
//  Created by 이원창 on 2020/05/26.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3000 + 1
using namespace std;

vector<int>* station;
int n = 0;
bool cycle;
bool visit[MAX];
bool check[MAX];
int BFS(int);
void DFS(int, int, int);
int main(int argc, const char * argv[]) {
    int num = 0;
    int num2 = 0;
    int start = 0;
    vector<int> ans;

    scanf("%d", &n);
    station = new vector<int>[n + 1];
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &num, &num2);
        station[num].push_back(num2);
        station[num2].push_back(num);
    }
    
    for (int i = 1; i <= n; i++){
        memset(visit, false, sizeof(visit));
        cycle = false;
        
        start = i;
        DFS(i, start, 0);
        
        if (cycle == true)
            check[i] = true;
    }
    
    for (int i = 1; i <= n; i++){
        if (check[i] == true){
            ans.push_back(0);
            continue;
        }
        ans.push_back(BFS(i));
    }
    
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}
void DFS(int cur, int start, int line){
    if (cur == start && line >= 2){
        cycle = true;
        return;
    }
    
    visit[cur] = true;
    for (int i = 0; i < station[cur].size(); i++){
        int next = station[cur][i];
        if(visit[next] == false)
            DFS(next, start, line + 1);
        else{
            if(next == start && line >= 2)
                DFS(next, start, line);
        }
        
        if (cycle == true)
            return;
    }
}

int BFS(int a){
    int cnt = 0;
    memset(visit, false, sizeof(visit));
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));

    visit[a] = true;
    while (q.empty() == 0){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (check[cur] == true)
            return cnt;
        
        for (int i = 0; i < station[cur].size(); i++){
            int next = station[cur][i];
            if (visit[next] == false){
                visit[next] = true;
                q.push(make_pair(next, cnt + 1));
            }
        }
    }
    
    return cnt;
}
