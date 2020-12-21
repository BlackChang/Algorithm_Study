//
//  main.cpp
//  Roma_num_making
//
//  Created by 이원창 on 2020/12/21.
//

#include <iostream>
using namespace std;

int n = 0;
int result = 0;
int visit[1001] = {0, };
int roma[4] = {1, 5, 10, 50};
void go(int d, int cnt, int total){
    if(cnt == n){
        if(visit[total] == 0){
            visit[total] = 1;
            result++;
        }
        return;
    }
    for(int i = d; i < 4; i++){
        go(i, cnt + 1, total + roma[i]);
    }
}
int main(int argc, const char * argv[]) {
    cin >> n;
    go(0, 0, 0);
    
    cout << result << endl;
    return 0;
}

