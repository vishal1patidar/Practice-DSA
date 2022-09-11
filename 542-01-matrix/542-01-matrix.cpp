class Solution {
public:
    void bfs(vector<vector<int>>& ans , vector<vector<int>>& vis , vector<vector<int>>& mat , int rowSize , int colSize){
        queue<pair<pair<int,int>,int>> q;
        
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[0].size() ; j++){
                if(mat[i][j] == 0){
                    q.push({{i , j} , 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[row][col] = dis;
            
            if(row - 1 >= 0 && vis[row-1][col] == -1){
                q.push({{row-1 , col} , dis + 1});
                vis[row-1][col] = 1;
            }
            
            if(col - 1 >= 0 && vis[row][col-1] == -1){
                q.push({{row , col-1} , dis + 1});
                vis[row][col-1] = 1;
            }
            
            if(row + 1 < rowSize && vis[row+1][col] == -1){
                q.push({{row+1 , col} , dis + 1});
                vis[row+1][col] = 1;
            }
            
            if(col + 1 < colSize && vis[row][col+1] == -1){
                q.push({{row , col+1} , dis + 1});
                vis[row][col+1] = 1;
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> ans(mat.size() , vector<int> (mat[0].size()));
        vector<vector<int>> vis(mat.size() , vector<int> (mat[0].size() , -1));
        
        bfs(ans , vis , mat , mat.size() , mat[0].size());
        
        return ans;      
    }
};