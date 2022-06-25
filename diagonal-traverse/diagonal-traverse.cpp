class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>ans;
        int i=0,j=0;
        int dir=0;
        while(i<m && j<n){
          
            if(dir==0){
                while(i>=0 && j>=0 && i<m && j<n){
                    ans.push_back(mat[i--][j++]);
                }
                i++;
                if(j>=n){
                    j--;
                    i++;
                }
               
                dir=1;
            }else{
                while(i>=0 && j>=0 && i<m && j<n){
                    ans.push_back(mat[i++][j--]);
                }
                j++;
                if(i>=m){
                    j++;
                    i--;
                }
                
                dir=0;
            }
            
        }
        return ans;
    }
};