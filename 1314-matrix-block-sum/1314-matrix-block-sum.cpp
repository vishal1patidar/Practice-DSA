#include <iostream>

class Solution {
public:

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
              
    vector<vector<int>> sol(mat.size(), vector<int>(mat[0].size(),0));
     
//Horizontal prefix sum only
        
        for (int i=0; i<mat.size();++i){
            for (int j=1; j<mat[0].size();++j){
              mat[i][j]+=mat[i][j-1];  
            }
        }  
        for (int i=0; i<mat.size();++i){
            
            // Max and min values for the sum of elements i - k <= r <= i + k,            
            int maxr = std::min(i+k, static_cast<int>(mat.size()-1)); 
            int minr = std::max(i-k, 0); 
                     
            for (int j=0; j<mat[0].size();++j){
            //Sum up all lines r such as i - k <= r <= i + k
             for (int r=minr; r<=maxr ;++r){
                 
              int jp = std::min(j+k, static_cast<int>(mat[0].size()-1));   
              
               //Didn't yet cover an horizontal block of size 2*k  (because  j <= k)   
               if (j-k<=0){
                   sol[i][j]+=mat[r][jp];
               }//Covered a block of size 2*k then substract the previous elements of the line
               else{       
               sol[i][j]+=mat[r][jp]-mat[r][j-k-1];  
                  }  
              }
           }             
        }
        return sol;
   }
};