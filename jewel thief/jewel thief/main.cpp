//
//  main.cpp
//  jewel thief
//
//  Created by 이원창 on 2020/08/26.
//  Copyright © 2020 이원창. All rights reserved.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel(n);
    multiset<int> bags;

    for(int i = 0; i < n; i++)
        cin >> jewel[i].second >> jewel[i].first;
    
    for(int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        bags.insert(temp);
    }
    
    sort(jewel.begin(), jewel.end(), greater<>());
    long long sum = 0;
    multiset<int>::iterator it;

    for(int i = 0; i < n; i++){
        int m = jewel[i].second;
        int v = jewel[i].first;
        it = bags.lower_bound(m);
        if(it != bags.end()){
            sum += v;
            bags.erase(it);
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
