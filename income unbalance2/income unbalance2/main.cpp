//
//  main.cpp
//  income unbalance2
//
//  Created by 이원창 on 2020/11/19.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int iter = 0;
    vector<int> ans;
    cin >> iter;
    for(int i = 0; i < iter; i++){
        int num = 0;
        int sum = 0;
        cin >> num;
        vector<int> p;
        for(int j = 0; j < num; j++){
            int temp = 0;
            cin >> temp;
            sum += temp;
            p.push_back(temp);
        }
        double avg = 0;
        avg = sum / num;
        int cnt = 0;
        for(int j = 0; j < num; j++){
            if(p[j] <= avg)
                cnt++;
        }
        ans.push_back(cnt);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << '#' << i + 1 << ' ';
        cout << ans[i] << endl;
    }
    return 0;
}
