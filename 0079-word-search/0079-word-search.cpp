class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int r,int c,int i,vector<vector<char>> &board,string &word){
        int n = board.size();
        int m = board[0].size();
        if(r < 0 or c < 0 or r >= n or c >= m or board[r][c] != word[i] or board[r][c] == '#'){
            return false;
        }
        if(i == word.size() - 1){
            return true;
        }
        char temp = board[r][c];
        board[r][c] = '#'; 
        bool op1 = dfs(r + 1,c,i + 1,board,word);
        bool op2 = dfs(r,c + 1,i + 1,board,word);
        bool op3 = dfs(r - 1,c,i + 1,board,word);
        bool op4 = dfs(r,c - 1,i + 1,board,word);
        board[r][c] = temp;
        return op1 or op2 or op3 or op4;
    }
};