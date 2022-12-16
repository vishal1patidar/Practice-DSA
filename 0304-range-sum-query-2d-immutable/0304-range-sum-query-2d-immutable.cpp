class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        mat = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i = 1 ; i <= m; i++){
            for(int j = 1; j <= n; j++){
                    mat[i][j] = matrix[i-1][j-1] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return mat[row2+1][col2+1] - mat[row1][col2 + 1] - mat[row2 + 1][col1] + mat[row1][col1];
    }
};