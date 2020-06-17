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
vector<long long int> num;
vector<int> ops;
pair<long long int, long long int> ans;
void dfs(long long int, long long int, int, int);
int main(int argc, const char * argv[]) {
    ans.first = LLONG_MIN;
    ans.second = LLONG_MAX;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        long long int temp = 0;
        scanf("%lld", &temp);
        num.push_back(temp);
    }

    for(int i = 0; i < 4; i++)
        scanf("%d", &op[i]);
        
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < op[i]; j++)
            ops.push_back(i + 1);
    }
    visit = new bool[n - 1];

    memset(visit, false, sizeof(bool)*(n - 1));
    for(int i = 0; i < n - 1; i++){
        if(!visit[i]){
            visit[i] = true;
            dfs(num[0], num[1], ops[i], 1);
            visit[i] = false;
        }
    }
    
    printf("%lld\n%lld\n", ans.first, ans.second);
    return 0;
}
void dfs(long long int num1, long long int num2, int opr, int idx){
    long long int temp = 0;
    if(opr == 1)
        temp = num1 + num2;
    else if(opr == 2)
        temp = num1 - num2;
    else if(opr == 3)
        temp = num1 * num2;
    else if(opr == 4)
        temp = num1 / num2;
    
    if(idx == n - 1){
        if(temp > ans.first)
            ans.first = temp;

        if(temp < ans.second)
            ans.second = temp;
        return;
    }
    for(int i = 0; i < n - 1; i++){
        if(!visit[i]){
            visit[i] = true;
            dfs(temp, num[idx + 1], ops[i], idx + 1);
            visit[i] = false;
        }
    }
}
