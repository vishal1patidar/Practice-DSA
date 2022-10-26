class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        
        int rowStart=0;
        int colStart=0;
        int rowEnd=n-1;
        int colEnd=m-1;
        int dir=1;
        
        while(rowStart<=rowEnd and colStart<=colEnd){
            if(dir==1){
                for(int i=colStart;i<=colEnd;i++){
                    ans.push_back(matrix[rowStart][i]);
                }
                rowStart++;
                dir=2;
            }
            
            if(dir==2){
                for(int i=rowStart;i<=rowEnd;i++){
                    ans.push_back(matrix[i][colEnd]);
                }
                colEnd--;
                dir=3;
            }
            
            if(dir==3){
                for(int i=colEnd;i>=colStart;i--){
                    ans.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
                dir=4;
            }
            
            if(dir==4){
                for(int i=rowEnd;i>=rowStart;i--){
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
                dir=1;
            }
        }
        vector<int> res;
        for(int i=0;i<m*n;i++){
            res.push_back(ans[i]);
        }
        return res;
 
    }
};