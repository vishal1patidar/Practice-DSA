class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,int val){
        
        int n=board.size();
        for(int i=0;i<n;i++){
            
            // row checking 
            if(board[row][i]=='0'+val)
                return false;
            // col checking
            if(board[i][col]=='0'+val)
                return false;
            // 3*3 matrix checking 
            if(board[3*(row/3)+ i/3][3*(col/3)+i%3]=='0'+val)
                return false;
        }
        return true;
    
    }
    bool solve(vector<vector<char>>& board){
        int n=board[0].size();
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                // cell empty
                 if(board[row][col] == '.'){
                
                    for(int val=1;val<=9;val++){
                        if(issafe(board,row,col,val)){
                            board[row][col] = '0' + val;
                            // recursive call
                            bool agekasolutionPossible=solve(board);
                            if(agekasolutionPossible)
                                return true;
                            else{
                                 // backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};