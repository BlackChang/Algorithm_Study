//
//  main.cpp
//  tree_traversal
//
//  Created by 이원창 on 2020/06/05.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n = 0;
vector<char> v[26];
vector<char> ans;
void preorder(int, int);
void inorder(int, int);
void postorder(int, int);
int main(int argc, const char * argv[]) {
    char tmp1;
    char tmp2;
    char tmp3;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%c %c %c", &tmp1, &tmp2, &tmp3);
        getchar();
        
        int idx = (int)(tmp1 - 'A');
        v[idx].push_back(tmp2);
        v[idx].push_back(tmp3);
    }
    
    preorder(0, 0);
    for(int i = 0; i < n; i++)
        printf("%c", ans[i]);
    printf("\n");

    ans.clear();
    inorder(0, 0);
    for(int i = 0; i < n; i++)
        printf("%c", ans[i]);
    printf("\n");
    
    ans.clear();
    postorder(0, 0);
    for(int i = 0; i < n; i++)
        printf("%c", ans[i]);
    printf("\n");

    return 0;
}
void preorder(int idx, int num){
    int left = (int)(v[idx][0] - 'A');
    int right = (int)(v[idx][1] - 'A');
    
    ans.push_back((char)(idx + 'A'));
    if(v[idx][0] != '.')
        preorder(left, num + 1);
    
    if(v[idx][1] != '.')
        preorder(right, num + 1);
}
void inorder(int idx, int num){
    int left = (int)(v[idx][0] - 'A');
    int right = (int)(v[idx][1] - 'A');
    
    if(v[idx][0] != '.')
        inorder(left, num + 1);

    ans.push_back((char)(idx + 'A'));

    if(v[idx][1] != '.')
        inorder(right, num + 1);

}
void postorder(int idx, int num){
    int left = (int)(v[idx][0] - 'A');
    int right = (int)(v[idx][1] - 'A');
    
    if(v[idx][0] != '.')
        postorder(left, num + 1);
    
    if(v[idx][1] != '.')
        postorder(right, num + 1);

    ans.push_back((char)(idx + 'A'));
}
