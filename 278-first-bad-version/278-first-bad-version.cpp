// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


class Solution {
public:
    int firstBadVersion(int n) {
    int i=1, m;
    while(i<=n)
    {
         m =  ((unsigned)i+(unsigned)n)/2;
         if (isBadVersion(m) == true && isBadVersion(m-1) == false)
           break;  
         else if(isBadVersion(m) == true)
             n = m ;
         else
             i = m+1;
    }      
    return m;  
    }
};