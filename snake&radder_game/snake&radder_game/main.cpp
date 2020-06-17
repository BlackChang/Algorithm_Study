//
//  main.cpp
//  snake&radder_game
//
//  Created by 이원창 on 2020/06/17.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, m;
    int x, y;
    int board[101];
    int check[101];
    bool rs[101];
    bool snake[101];
    bool visit[101];
    queue<int> q;
    memset(board, 0, sizeof(board));
    memset(rs, 0, sizeof(rs));
    memset(snake, false, sizeof(snake));
    memset(visit, false, sizeof(visit));
    memset(check, 0, sizeof(check));
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        board[x] = y;
        rs[x] = true;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        board[x] = y;
        rs[x] = true;
    }
    
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(visit[100])
            break;
        for(int i = 1; i <=  6; i++){
            int newX = x + i;
//            if(visit[100]){
//                printf("%d\n", check[100]);
//                break;
//            }
            if(newX > 100 || visit[newX])
                continue;
            if(rs[newX])
                newX = board[newX];
            
            if(!visit[newX]){
                visit[newX] = true;
                check[newX] = check[x] + 1;
                q.push(newX);
            }
        }
    }
    printf("%d\n", check[100]);
    
//        for(int i = 1; i <= 100; i++){
//            printf("%d", check[i]);
//            if(i % 10 == 0)
//                printf("\n");
//        }
    return 0;
}
