//
//  main.cpp
//  chicken_halfNhalf
//
//  Created by 이원창 on 2020/12/21.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a = 0;
    int b = 0;
    int c = 0;
    int x = 0;
    int y = 0;
    int result = 0;
    int temp = 0;
    
    cin >> a >> b >> c >> x >> y;
    result = a * x + b * y;
    
    if(x < y){
        if(b > 2 * c)
            temp = 2 * y * c;
        else
            temp = 2 * c * x + (y - x) * b;
    }
    else{
        if(a > 2 * c)
            temp = 2 * x * c;
        else
            temp = 2 * c * y + (x - y) * a;
    }
    if(result > temp)
        result = temp;

    cout << result << endl;
    return 0;
}
