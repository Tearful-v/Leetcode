class Solution {
public:

    bool solve(vector<vector<char>>& board, int row[9], int col[9], int box[9]){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.')
                    continue;
                for(int x = 1; x <= 9; x++){
                    int bit = 1 << (x-1);
                    int index = (i/3)*3 + j/3;
                    if(!(row[i] & bit) && !(col[j] & bit) && !(box[index] & bit)){
                        board[i][j] = '0' + x;
                        row[i] |= bit;
                        col[j] |= bit;
                        box[index] |= bit;
                        if(solve(board, row, col, box)) return true;
                        row[i] &= ~bit;
                        col[j] &= ~bit;
                        box[index] &= ~bit;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int row[9] = {};
        int col[9] = {};
        int box[9] = {};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] == '.')
                    continue;
                int digit = board[i][j] - '1';
                int bit = 1 << digit;
                int index = (i/3)*3 + j/3;
                row[i] |= bit;
                col[j] |= bit;
                box[index] |= bit;
            }
        }
        solve(board, row, col, box);
        return;
    }
};