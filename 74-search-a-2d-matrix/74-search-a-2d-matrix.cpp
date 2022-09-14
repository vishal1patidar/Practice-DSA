class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        long long m=matrix.size();
        long long n=matrix[0].size();
        long long l=0, r=m-1,mid;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]>target)
                r=mid-1;
            else
                l=mid+1;
            
        }
        
        long long row;
        if(matrix[mid][0]>target)
        {
            
        
            row=mid-1;
            if(row<0)
                return false;
        }
        else
            row=mid;
        l=0,r=n-1;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            if(matrix[row][mid]==target)
                return true;
             else if(matrix[row][mid]>target)
                r=mid-1;
            else
                l=mid+1;
            
        }
        return false;
    }
};