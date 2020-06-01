//
//  main.cpp
//  div3mul2
//
//  Created by 이원창 on 2020/05/29.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100

using namespace std;
int n = 0;
bool visit[MAX];
bool tale = false;
vector<unsigned long long int> a;
vector<unsigned long long int> ans;
void dfs(int, int);
int main(int argc, const char * argv[]) {
    unsigned long long int temp = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%lld", &temp);
        a.push_back(temp);
    }
    
    for (int i = 0; i < a.size(); i++)
        dfs(i, 1);
    
    return 0;
}
void dfs(int idx, int n) {
    visit[idx] = true;
    ans.push_back(a[idx]);
    
    if (n == a.size()) {
        for (int i = 0; i < ans.size(); i++)
            printf("%lld ", ans[i]);
        printf("\n");
        return;
    }
    
    for (int i = 0; i < a.size(); i++) {
        if (a[idx] % 3 == 0 && a[idx] / 3 == a[i] && idx != i && !visit[i])
            dfs(i, n + 1);
        
        if (a[idx] * 2 == a[i] && idx != i && !visit[i])
            dfs(i, n + 1);
    }
    visit[idx] = false;
    ans.pop_back();
}
