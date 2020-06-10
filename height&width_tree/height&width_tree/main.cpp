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
struct tree{
    int root;
    int l;
    int r;
    tree() : root(-1), l(-1), r(-1) {}
};
vector<tree> v;
vector<int>* t;
int h = 0;
int x = 1;
int height = 0;
int width = 0;
void getHeight(int);
void inorder(int);
int main(int argc, const char * argv[]) {
    int root = 1;
    pair<long long int, long long int> ans = make_pair(0, 0);
    
    scanf("%d", &width);
    v.resize(width + 1);
    for(int i = 0; i < width; i++){
        int parent = 0;
        int left = 0;
        int right = 0;
        
        scanf("%d %d %d", &parent, &left, &right);
        v[parent].l = left;
        v[parent].r = right;
        v[left].root = parent;
        v[right].root = parent;
    }
        
    while(v[root].root != -1)
        root = v[root].root;
    
    getHeight(root);
    
    t = new vector<int>[height + 1];
    h = 0;
    
    inorder(root);
    for(int i = 1; i <= height; i++){
        int temp = t[i].back() - t[i].front() + 1;
        if(temp > ans.second){
            ans.first = i;
            ans.second = temp;
        }
    }

    printf("%lld %lld\n", ans.first, ans.second);
    return 0;
}
void getHeight(int idx){
    h += 1;
    if(h > height)
        height = h;
    
    if(v[idx].l != -1)
        getHeight(v[idx].l);
        
    if(v[idx].r != -1)
        getHeight(v[idx].r);
    h -= 1;
}
void inorder(int idx){
    h += 1;
    if(v[idx].l != -1){
        inorder(v[idx].l);
        t[h].push_back(x);
        x += 1;
    }
    else{
        t[h].push_back(x);
        x += 1;
    }
    
    if(v[idx].r != -1)
        inorder(v[idx].r);
    
    h -= 1;
}
