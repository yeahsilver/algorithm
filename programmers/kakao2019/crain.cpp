#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define for(i, start, end) for(int i = start; i < end; i++)

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    
    vector<int> basket;
    
    for(i, 0, moves.size()) {
        
        // for문 돌려 0이 아닌 것 체크한 뒤 0으로 바꾸기 + stack에 푸시
        int current = moves[i]-1;
        
        int value = 0;
        int emptySpaceNum = 0;
        
        for(j, 0, board.size()) {
            if(board[current][j] != 0) {
                value = board[current][j];
                
                emptySpaceNum = j;
                cout << emptySpaceNum << '\n';
                break;
            }
        }
        
        if(emptySpaceNum < board.size()) {
            basket.push_back(value);
            board[current][emptySpaceNum] = 0;
            
            // 인형이 터지는 조건: 2개가 연속으로 닿아있음 + 개수가 2개 이상이여야함
            if(basket.size() >= 2 && value == basket[basket.size()-2]) {
                basket.pop_back();
                basket.pop_back();
                
                answer+=2;
            }
        }
    }
    return answer;
    
}

int main(void) {
    vector<vector<int> > board;
    board[0].push_back(0);
    board[0].push_back(0);
    board[0].push_back(0);
    board[0].push_back(0);
    board[0].push_back(0);

    board[1].push_back(0);
    board[1].push_back(0);
    board[1].push_back(1);
    board[1].push_back(0);
    board[1].push_back(3);

    board[2].push_back(0);
    board[2].push_back(2);
    board[2].push_back(5);
    board[2].push_back(0);
    board[2].push_back(1);

    board[3].push_back(4);
    board[3].push_back(2);
    board[3].push_back(4);
    board[3].push_back(4);
    board[3].push_back(2);

    board[4].push_back(3);
    board[4].push_back(5);
    board[4].push_back(1);
    board[4].push_back(3);
    board[4].push_back(1);

    vector<int> moves;
    moves.push_back(1);
    moves.push_back(5);
    moves.push_back(3);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(2);
    moves.push_back(1);
    moves.push_back(4);


    cout << solution(board, moves);
}