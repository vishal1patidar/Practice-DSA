class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        vector<vector<int>> dist(m, vector<int>(n , 100000));
        queue<vector<int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==0)
                { 
                    dist[i][j] = 0;
                    q.push({ i, j});
                }
                else
                    v[i][j]=100000;
            }
        }        
        vector<vector<int>> moves = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        
        while(!q.empty())
        {
            int x = q.front()[0], y = q.front()[1]; 
            q.pop();
            for(auto mo : moves)
            {
                int newx = x + mo[0], newy = y + mo[1];
                
                if(newx>=0 && newx < m && newy>=0 && newy<n)
                {
                    if(v[newx][newy] > v[x][y] + 1)
                    {
                        v[newx][newy] = v[x][y] + 1 ;
                        q.push({newx, newy});
                    }
                }
            }
        }       
        return v;            
    }
};