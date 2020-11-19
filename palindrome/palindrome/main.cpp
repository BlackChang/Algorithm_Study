//
//  main.cpp
//  palindrome
//
//  Created by 이원창 on 2020/11/19.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPalindrome(string);
int main(int argc, const char * argv[]) {
    int iter = 0;
    int start = 0;
    int end = 0;
    vector<int> ans;
    cin >> iter;
    for(int i = 0; i < iter; i++){
        int cnt = 0;
        cin >> start >> end;
        for(int j = (int)sqrt(start); j <= (int)sqrt(end); j++){
            string str = to_string(j);
            if(isPalindrome(str)){
                if(isPalindrome(to_string((int)pow(j, 2)))){
                    if(pow(j, 2) >= start && pow(j, 2) <= end)
                        cnt++;
                }
            }
        }
        ans.push_back(cnt);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << '#' << i + 1 << ' ';
        cout << ans[i] << endl;
    }
    return 0;
}
bool isPalindrome(string str){
    if(str.size() == 1){
        return true;
    }
    else{
        for(int i = 0; i < str.size() / 2; i++){
            if(str[i] != str[str.size() - i - 1])
                return false;
        }
    }
    return true;
}
