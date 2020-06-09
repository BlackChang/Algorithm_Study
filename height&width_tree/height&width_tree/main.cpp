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
vector<int> v[10001];
int h = 0;
int x = 1;
int height = 0;
int width = 0;
int** tree;
void getHeight(int);
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
    
    getHeight(root);
    tree = new int*[height + 1];
    for(int i = 0; i <= height; i++)
        tree[i] = new int[width + 1];

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
        int dis = last - start + 1;
        if(dis > ans.second){
            ans.first = i;
            ans.second = dis;
        }
    }

    printf("%d %d\n", ans.first, ans.second);
    return 0;
}
void getHeight(int idx){
    h += 1;
    if(h > height)
        height = h;
    
    if(v[idx][0] != -1)
        getHeight(v[idx][0]);
    
    if(v[idx][1] != -1)
        getHeight(v[idx][1]);
    
    h -= 1;
}
void inorder(int idx){
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
}
