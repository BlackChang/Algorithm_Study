//
//  main.cpp
//  tetromino
//
//  Created by 이원창 on 2020/04/19.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int m = 0;
    int n = 0;
    int max = 0;
    int temp = 0;
    int** arr;
    
    scanf("%d %d", &n, &m);
    while(n < 4 && (m > 500 || m <= 0)){
        scanf("%d %d", &n, &m);
    }
    arr = new int*[m];
    for(int i = 0; i < n; i++)
        arr[i] = new int[m];
    
    for(int i = 0; i < n; i++){
        getchar();
        for(int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 2; j++){
            temp = arr[i+1][j] + arr[i+1][j+1] + arr[i][j+1] + arr[i][j+2];
            if(max < temp)
                max = temp;
            temp = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
            if(max < temp)
                max = temp;
            temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
            if(max < temp)
                max = temp;
            temp = arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+1];
            if(max < temp)
                max = temp;
            temp = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
            if(max < temp)
                max = temp;
            temp = arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+2];
            if(max < temp)
                max = temp;
        }
    }
    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < m - 1; j++){
            temp = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
            if(max < temp)
                max = temp;
            temp = arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j];
            if(max < temp)
                max = temp;
            temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
            if(max < temp)
                max = temp;
            temp = arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
            if(max < temp)
                max = temp;
            temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j+1];
            if(max < temp)
                max = temp;
            temp = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
            if(max < temp)
                max = temp;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 3; j++){
            temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
            if(max < temp)
                max = temp;
        }
    }
    for(int i = 0; i < n - 3; i++){
        for(int j = 0; j < m; j++){
            temp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
            if(max < temp)
                max = temp;
        }
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            temp = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i][j+1];
            if(max < temp)
                max = temp;
        }
    }

    printf("%d\n", max);
    return 0;
}
