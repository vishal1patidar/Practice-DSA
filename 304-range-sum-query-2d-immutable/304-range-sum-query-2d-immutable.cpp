class NumMatrix {
public:
    vector<vector<int>> prefix;
        
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix.resize(m+1);
        fill(prefix.begin(), prefix.end(), vector<int> (n+1, 0));
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1] - prefix[row2+1][col1] - prefix[row1][col2+1] + prefix[row1][col1];
    }
};
