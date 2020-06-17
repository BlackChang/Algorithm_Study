//
//  main.cpp
//  push_operator_14888
//
//  Created by 이원창 on 2020/06/17.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
int n = 0;
int op[4];
bool* visit;
vector<int> num;
vector<int> ops;
vector<int> per;
pair<int, int> ans;
void dfs(int, int, int, int);
int main(int argc, const char * argv[]) {
    ans.first = 0;
    ans.second = INT_MAX;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int temp = 0;
        scanf("%d", &temp);
        num.push_back(temp);
    }

    for(int i = 0; i < 4; i++)
        scanf("%d", &op[i]);
        
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < op[i]; j++)
            ops.push_back(i + 1);
    }
    visit = new bool[(int)ops.size()];

    memset(visit, false, sizeof(visit));
    for(int i = 0; i < (int)ops.size(); i++){
        if(!visit[i]){
            visit[i] = true;
            per.push_back(ops[i]);
            dfs(num[0], num[1], ops[i], 1);
            visit[i] = false;
            per.pop_back();
        }
    }
    
    printf("%d\n%d\n", ans.first, ans.second);
    return 0;
}
void dfs(int num1, int num2, int opr, int idx){
    int temp = 0;
    if(opr == 1)
        temp = num1 + num2;
    else if(opr == 2)
        temp = num1 - num2;
    else if(opr == 3)
        temp = num1 * num2;
    else if(opr == 4)
        temp = num1 / num2;
    
    if(idx == (int)ops.size()){
        if(temp > ans.first)
            ans.first = temp;

        if(temp < ans.second)
            ans.second = temp;
        return;
    }
    for(int i = 0; i < (int)ops.size(); i++){
        if(!visit[i]){
            visit[i] = true;
            per.push_back(ops[i]);
            dfs(temp, num[idx + 1], ops[i], idx + 1);
            visit[i] = false;
            per.pop_back();
        }
    }
}
