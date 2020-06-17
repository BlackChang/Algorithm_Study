//
//  main.cpp
//  word_math
//
//  Created by 이원창 on 2020/06/15.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
vector<string> v;
int n = 0;
int main(int argc, const char * argv[]) {
    string temp;
    scanf("%d", &n);
    getchar();
        
    for(int i = 0; i < n; i++){
        getline(cin, temp);
        v.push_back(temp);
    }

    return 0;
}
