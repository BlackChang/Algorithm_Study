//
//  main.cpp
//  hide&seek3
//
//  Created by 이원창 on 2020/06/02.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#define MAX 100001

using namespace std;
bool visit[MAX];
int dist[MAX];
int ans[MAX];
int m[] = {2, -1, 1};
int n = 0;
int k = 0;
int cur = 0;
int cnt = 0;
bool tel = false;
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &k);

    dist[n] = 0;
    visit[n] = true;
    ans[n] = 0;
    
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int next = 0;
        for(int i = 0; i < 3; i++){
            if(i != 0){
                next = cur + m[i];
                tel = false;
            }
            else{
                next = cur * m[i];
                tel = true;
            }
            if(0 <= next && next < MAX){
                if(visit[next] == false){
                    visit[next] = true;
                    dist[next] = dist[cur] + 1;
                    if(tel)
                        ans[next] = ans[cur];
                    else
                        ans[next] = ans[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
    
    printf("%d\n", ans[k]);
    return 0;
}
