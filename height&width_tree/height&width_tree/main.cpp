//
//  main.cpp
//  height&width_tree
//
//  Created by 이원창 on 2020/06/07.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[10000];
int h = 0;
int x = 1;
int height = 0;
int width = 0;
int tree[2500][10000];
void inorder(int);
int main(int argc, const char * argv[]) {
    int tmp1 = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int root = 0;
    pair<int, int> ans = make_pair(0, 0);
    
    scanf("%d", &width);
    for(int i = 0; i < width; i++){
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        if(i == 0)
            root = tmp1;
        
        v[tmp1].push_back(tmp2);
        v[tmp1].push_back(tmp3);
    }
    
    inorder(root);
    for(int i = 1; i <= height; i++){
        int start = 10000;
        int last = 0;
        for(int j = 1; j <= width; j++){
            if(tree[i][j] != 0){
                if(start > j)
                    start = j;
                last = j;
            }
        }
        if((last - start + 1) > ans.second){
            ans.first = i;
            ans.second = last - start + 1;
        }
    }
    printf("%d %d\n", ans.first, ans.second);
    
    return 0;
}
void inorder(int idx){
    h += 1;
    if(h > height)
        height = h;
    
    if(v[idx][0] == -1){
        tree[h][x] = idx;
        x += 1;
    }
    
    if(v[idx][0] != -1){
        inorder(v[idx][0]);
        tree[h][x] = idx;
        x += 1;
    }
    
    if(v[idx][1] != -1)
        inorder(v[idx][1]);
    
    h -= 1;
}
