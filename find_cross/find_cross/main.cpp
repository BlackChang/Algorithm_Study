//
//  main.cpp
//  find_cross
//
//  Created by 이원창 on 2020/12/21.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n = 0;
    int m = 0;
    vector<vector<int>> v;
    cin >> n >> m;
    
    char **map = new char*[n];
    
    for(int i = 0; i < n; i++){
        map[i] = new char[m];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == '*'){
                
            }
        }
    }
    return 0;
}
