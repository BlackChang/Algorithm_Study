//
//  main.cpp
//  set
//
//  Created by 이원창 on 2020/06/03.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m = 0;
int s[20];
void add(int);
void remove(int);
void check(int);
void toggle(int);
void all();
void empty();
int main() {
    ios_base::sync_with_stdio(0);
    int num = 0;
    char temp[6];
    
    for(int i = 0; i < 20; i++)
        s[i] = 0;
    
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%s %d", temp, &num);
        
        if(strcmp(temp, "add") == 0)
            add(num);
        else if(strcmp(temp, "remove") == 0)
            remove(num);
        else if(strcmp(temp, "check") == 0)
            check(num);
        else if(strcmp(temp, "toggle") == 0)
            toggle(num);
        else if(strcmp(temp, "all") == 0)
            all();
        else if(strcmp(temp, "empty") == 0)
            empty();
    }
    return 0;
}
void add(int num){
    s[num - 1] = 1;
}
void remove(int num){
    s[num - 1] = 0;;
}
void check(int num){
    if(s[num - 1] == 1)
        printf("1\n");
    else
        printf("0\n");
}
void toggle(int num){
    if(s[num - 1] == 1)
        s[num - 1] = 0;
    else
        s[num - 1] = 1;
}
void all(){
    for(int i = 0; i < 20; i++)
        s[i] = 1;
}
void empty(){
    for(int i = 0; i < 20; i++)
        s[i] = 0;
}
