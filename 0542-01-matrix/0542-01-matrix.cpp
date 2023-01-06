class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n=mat.size();
        int m=mat[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
       
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
       
       int dx[]={-1,0,+1,0};
       int dy[]={0,+1,0,-1};
    
         while(!q.empty())
         {
            
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            ans[row][col]=dist;
          for(int i=0;i<4;i++)
          {
              int nrow=row+dx[i];
              int ncol=col+dy[i];

               if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol])
               {
                    q.push({{nrow,ncol},dist+1});
                    vis[nrow][ncol]=1;
               }
          }
          
         }
     return ans;
    }
};