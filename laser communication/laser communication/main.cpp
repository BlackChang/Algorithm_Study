//
//  main.cpp
//  laser communication
//
//  Created by 이원창 on 2020/08/26.
//  Copyright © 2020 이원창. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
struct Info{
    int x;
    int y;
    int dir;
    int cnt;
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(int argc, const char * argv[]) {
    int w = 0;
    int h = 0;
    int cnt[100][100];
    char map[100][100];
    vector<pair<int, int>> laser;
    queue<Info> q;
    cin >> w >> h;
    getchar();
    
    for(int i = 0; i < h; i++){
        memset(cnt[i], 100, sizeof(cnt[i]));
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map[i][j];
            if(map[i][j] == 'C')
                laser.push_back(make_pair(i, j));
        }
    }
    q.push(Info{laser[0].second, laser[0].first, -1, 0});
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().dir;
        int c = q.front().cnt;
        q.pop();
                
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 > nx || nx >= w || 0 > ny || ny >= h)
                continue;
            else if(map[ny][nx] == '*')
                continue;
            else {
                int nc = c;
                if(d != -1 && d != i)
                    nc = c + 1;
                if(cnt[ny][nx] >= nc){
                    cnt[ny][nx] = nc;
                    q.push(Info{nx, ny, i, nc});
                }
            }
        }
    }
    
    cout << cnt[laser[1].first][laser[1].second] << endl;
    return 0;
}
