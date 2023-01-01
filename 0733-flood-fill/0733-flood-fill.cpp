class Solution {
public:
    void bfs(int sr, int sc, int newcolor,vector<vector<int>>& ans,int initial){
              ans[sr][sc] = newcolor; //Setting new color to the cell
              vector<int> delrow = {-1,0,1,0}; //Left right up down traversal
              vector<int> delcol = {0,-1,0,1};
                int m = ans.size();
                int n = ans[0].size();      
                //Simple bfs
              queue<pair<int,int>> q;
              q.push({sr,sc});
              while(!q.empty()){
                  int r = q.front().first;
                  int c = q.front().second;
                  q.pop();
                  //Checking in its all adjacent directions
                     for(int i=0;i<4;i++){
                   int nrow = r+delrow[i];
                   int ncol = c+delcol[i];
                   if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && 
                   ans[nrow][ncol] == initial && ans[nrow][ncol] != newcolor){
                       ans[nrow][ncol]=newcolor;
                       q.push({nrow,ncol});
                   }
              }
              }
             


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector<vector<int>> ans = image;
         int m = ans.size();
         int n = ans[0].size();     
         int initial = ans[sr][sc]; //Storing the color to be altered
              bfs(sr,sc,color,ans,initial);
              return ans;
             }

};