//
//  main.cpp
//  death_knight
//
//  Created by 이원창 on 2020/06/16.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue<pair<int, int>> horse;
int** cnt;
int n = 0;
int r1 = 0;
int c1 = 0;
int r2 = 0;
int c2 = 0;
int r = 0;
int w = 0;
int newR[6] = {-2, -2, 0, 0, 2, 2};
int newC[6] = {-1, 1, -2, 2, -1, 1};
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    horse.push(make_pair(r1, c1));
    
    cnt = new int*[n];
    for(int i = 0; i < n; i++)
        cnt[i] = new int[n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cnt[i][j] = -1;
    }
    cnt[r1][c1] = 0;
    
    while (!horse.empty()) {
        int nR = 0;
        int nC = 0;
        int R = horse.front().first;
        int C = horse.front().second;
        horse.pop();
        for (int i = 0; i < 6; i++) {
            nR = R + newR[i];
            nC = C + newC[i];
            if (nR < 0 || nC >= n || nC < 0 || nR >= n)
                continue;
            else {
                if (cnt[nR][nC] != -1 && cnt[R][C] + 1 > cnt[nR][nC])
                    continue;
                
                cnt[nR][nC] = cnt[R][C] + 1;
                horse.push(make_pair(nR, nC));
            }
        }
    }
    
    printf("%d\n", cnt[r2][c2]);
    return 0;
}
