#include <string>
#include <vector>

using namespace std;

int sp = 0, ri[100], rj[100];
bool success = false;
int temp = 100000000;
bool visit(vector<vector<int>>, int, int, int);
void print_path(){
    int sum = 0;
    int straight = 0;
    int corner = 0;
    for (int i = 0; i < sp; i++) {
        if (ri[i] != ri[i - 2] && rj[i] != rj[i - 2])
            corner++;
        else
            straight++;
    }
    sum = straight*100 + corner*500;
    if(temp > sum)
        temp = sum;
}
bool visit(vector<vector<int>> board, int x, int y, int size) {
    board[x][y] = 1;
    ri[sp] = x;
    rj[sp] = y;
    sp++;
    if (x == size && y == size) {
        print_path();
        success = true;
    }
    
    if (!success && (board[x][y+1] == 0) && ((y + 1) <= size))
        visit(board, x, y + 1, size);
    if (!success && (board[x+1][y] == 0) && ((x + 1) <= size))
        visit(board, x + 1, y, size);
    if (!success && (board[x][y-1] == 0) && (y > 0))
        visit(board, x, y - 1, size);
    if (!success && (board[x-1][y] == 0) && (x > 0))
        visit(board, x - 1, y, size);
    
    sp -= 1;
    return success;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = (int)board.size();
    visit(board, 0, 0, size - 1);
    return answer;
}
int main(){
    vector<vector<int>> board;
    board = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
    printf("%d\n", solution(board));
}

