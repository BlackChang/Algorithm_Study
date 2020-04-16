#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int max_a = 0;
int len = 1;
int n = 0;
char** cnd;
void findMax();

int main(int argc, const char * argv[]) {
    while(n < 3 || n > 50){
        scanf("%d", &n);
    }
    cnd = new char*[n];

    for (int i = 0; i < n; i++)
        cnd[i] = new char[n];
    
    for(int i = 0; i < n; i++){
        getchar();
        for(int j = 0; j < n; j++){
            scanf("%c", &cnd[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(cnd[i][j] != cnd[i][j+1]){
                swap(cnd[i][j], cnd[i][j+1]);
                findMax();
                swap(cnd[i][j], cnd[i][j+1]);
            }
        }
    }
            
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(cnd[j][i] != cnd[j+1][i]){
                swap(cnd[j][i], cnd[j+1][i]);
                findMax();
                swap(cnd[j][i], cnd[j+1][i]);
            }
        }
    }
    printf("%d\n", max_a);

    return 0;
}

void findMax(){
    for(int k = 0; k < n; k++){
        len = 1;
        for(int l = 0; l < n-1; l++){
            if(cnd[k][l] == cnd[k][l+1]){
                len += 1;
            }
            else{
                if(max_a < len)
                    max_a = len;
                len = 1;
            }
        }
        if(max_a < len)
            max_a = len;
    }
    
    for(int k = 0; k < n; k++){
        len = 1;
        for(int l = 0; l < n-1; l++){
            if(cnd[l][k] == cnd[l+1][k]){
                len += 1;
            }
            else{
                if(max_a < len)
                    max_a = len;
                len = 1;
            }
        }
        if(max_a < len)
            max_a = len;
    }
}


