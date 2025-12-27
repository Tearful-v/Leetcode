class Solution {
public:

    int boxindex(int i, int j){
        return((i/3)*3 + j/3);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> row[9];
        std::unordered_set<char> col[9];
        std::unordered_set<char> box[9];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row[i].find(board[i][j]) != row[i].end()){
                        if(row[i].count(board[i][j]) == 1)
                            return false;
                    }
                    else{
                        row[i].insert({board[i][j]});
                    }
                    if(col[j].find(board[i][j]) != col[j].end()){
                        if(col[j].count(board[i][j]) == 1)
                            return false;
                    }
                    else{
                        col[j].insert({board[i][j]});
                    }
                    if(box[(boxindex(i,j))].find(board[i][j]) != box[(boxindex(i,j))].end()){
                        if(box[(boxindex(i,j))].count(board[i][j]) == 1)
                            return false;
                    }
                    else{
                        box[(boxindex(i,j))].insert({board[i][j]});
                    }
                }
            }
        }
        return true;
    }
};