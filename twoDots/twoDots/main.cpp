//
//  main.cpp
//  twoDots
//
//  Created by 이원창 on 2020/05/25.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int m = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int** check;
char** dots;
int cycle(int a,int b,int, int );
int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    getchar();
    
    dots = new char*[n];
    check = new int*[n];

    for(int i = 0; i < n; i++){
        dots[i] = new char[m];
        check[i] = new int[m];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            scanf("%c", &dots[i][j]);
        getchar();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j])
                continue;
            if(cycle(i, j, -1, -1)){
                printf("Yes\n");
                return 0;
            }
        }
    }
    
    printf("No\n");
    return 0;
}
int cycle(int a,int b,int c,int d){
    if(check[a][b])
        return 1;
    
    check[a][b] = 1;
    
    for(int k = 0; k < 4; k++){
        int x = a + dx[k];
        int y = b + dy[k];
        if(!(x == c && y == d)){
            if(x >= 0 && x < n && y >= 0 && y < m && (dots[x][y] == dots[a][b])){
                if(cycle(x, y, a, b))
                    return 1;
            }
        }
    }
    return 0;
}
