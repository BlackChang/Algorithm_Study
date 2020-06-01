//
//  main.cpp
//  hide&seek
//
//  Created by 이원창 on 2020/06/01.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;
bool visit[MAX];
int dist[MAX];
int m[] = {-1,1,2};
int n = 0;
int k = 0;
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
    
    return 0;
}
