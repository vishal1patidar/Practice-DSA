class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(r*c!=n*m) return mat;
        vector<vector<int>> grid(r,vector<int>(c));
        int r1=0,c1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[r1][c1]=mat[i][j];
                c1++;
                if(c1>=c){
                    c1=0;
                    r1++;
                }
            }
        }
        return grid;
    }
};