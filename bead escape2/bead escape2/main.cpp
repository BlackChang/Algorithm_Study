//
//  main.cpp
//  bead escape2
//
//  Created by 이원창 on 2020/07/30.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct N{
    int y;
    int x;
    int dis;
};
int depX = 0;
int depY = 0;
int n = 0;
int m = 0;
int dir = {-1, 1};
char** box;
int main(int argc, const char * argv[]) {
    queue<N> red;
    queue<N> blue;
    scanf("%d %d", &n, &m);
    box = new char*[n];
    getchar();
    
    for(int i = 0; i < n; i++)
        box[i] = new char[m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &box[i][j]);
            if(box[i][j] == 'R'){
                red.push({i, j, 1});
                box[i][j] = '.';
            }
            else if(box[i][j] == 'B'){
                blue.push({i, j, 1});
                box[i][j] = '.';
            }
            else if(box[i][j] == 'O'){
                depY = i;
                depX = j;
                box[i][j] = '.';
            }
        }
        getchar();
    }

    while(!red.empty()){
        int redX = red.front().x;
        int redY = red.front().y;
        int redDis = red.front().dis;
        
        int blueX = blue.front().x;
        int blueY = blue.front().y;
        int blueDis = blue.front().dis;
        
        red.pop();
        blue.pop();
        
        for(int i = 0; i < 2; i++){
            
        }
        if(redDis > 10){
            printf("-1\n");
            return 0;
        }
        
        
    }
    return 0;
}
