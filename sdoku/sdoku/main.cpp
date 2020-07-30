//
//  main.cpp
//  sdoku
//
//  Created by 이원창 on 2020/07/27.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
int board[9][9];
bool checkR[9][10] = {false, };
bool checkC[9][10] = {false, };
bool checkI[9][10] = {false, };
bool dfs(int, int);
int main(int argc, const char * argv[]) {
    for(int i = 0; i < 9; i++){
        int tmp1 = i / 3;
        for(int j = 0; j < 9; j++){
            int tmp2 = j / 3;
            int tmp = 0;
            scanf("%d", &tmp);
            board[i][j] = tmp;
            if(tmp != 0){
                checkR[i][tmp] = true;
                checkC[j][tmp] = true;
                checkI[(tmp1 * 3) + tmp2][tmp] = true;
            }
        }
    }
        
    dfs(0, 0);
    
    printf("\n");
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    
    return 0;
}
bool dfs(int x, int y){
    if (y == 9)
        return false;

    while(board[x][y]) {
        x = x + 1;
        if (x == 9) {
            x = 0;
            y = y + 1;
        }
        if (y == 9)
            return false;
    }

    int nx = x + 1;
    int ny = y;

    if (nx == 9) {
        nx = 0;
        ny = y + 1;
    }

    for (int i = 1; i < 10; i++) {
        if (!checkR[x][i] && !checkC[y][i] && !checkI[(x / 3) * 3 + (y / 3)][i]) {
            board[x][y] = i;
            checkR[x][i] = true;
            checkC[y][i] = true;
            checkI[(x / 3) * 3 + (y / 3)][i] = true;

            if(!dfs(nx, ny))
                return false;

            board[x][y] = 0;
            checkR[x][i] = false;
            checkC[y][i] = false;
            checkI[(x / 3) * 3 + (y / 3)][i] = false;
        }
    }
    return true;
}
