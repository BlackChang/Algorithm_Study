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
    int tmp, tmp2;
    int board[101];
    bool visit[101];
    vector<pair<int, int>> r;
    vector<pair<int, int>> s;
    queue<pair<int, int>> ans;
    memset(board, 0, sizeof(board));
    memset(visit, false, sizeof(visit));

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &tmp, &tmp2);
        r.push_back(make_pair(tmp, tmp2));
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &tmp, &tmp2);
        s.push_back(make_pair(tmp, tmp2));
    }
    ans.push(make_pair(1, 0));
    while(!ans.empty()){
        int x = ans.front().first;
        int check = ans.front().second;
        ans.pop();
        if(x == 100){
            printf("%d\n", check);
            break;
        }
        for(int i = 1; i <=  6; i++){
            int newX = x + i;
            if(newX > 100 && visit[newX])
                continue;
            
        }
    }
    
    return 0;
}
