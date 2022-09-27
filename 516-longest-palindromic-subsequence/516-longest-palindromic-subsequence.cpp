// class Solution {
// public:
//     int t[1000+1][1000+1];
    
//     int LCS(string& a,string& b, int m, int n){
//         if(n==0||m==0) return 0;
        
//         if(t[m][n]!=-1) return t[m][n];
        
//         if(a[m-1]==b[n-1]) return t[m][n]=1+ LCS(a,b,m-1,n-1);
//         else return t[m][n]=max(LCS(a,b,m-1,n),LCS(a,b,m,n-1));
//     }
    
//     int longestPalindromeSubseq(string s) {
//       string rev="";
//       int len=s.length();  
//       for(int i=len-1;i>=0;i--) rev+=s[i];
        
//       memset(t,-1,sizeof(t));  
//       return LCS(s,rev,len,len); 
//     }
// };
// TABULAR / BOTTOM-UP APPROACH

class Solution {
public:
    int longestPalindromeSubseq(string s) {
      string rev="";
        int len=s.length();  
      for(int i=len-1;i>=0;i--) rev+=s[i];
      int t[len+1][len+1];
      for(int i=0; i<len+1;i++) t[0][i]=0;
      for(int i=0; i<len+1;i++) t[i][0]=0;  
        
      for(int i=1; i<len+1; i++){
          for(int j=1; j<len+1; j++){
              if(s[i-1]==rev[j-1]){
                  t[i][j]=1+t[i-1][j-1];
              }
              else{
                  t[i][j]=max(t[i-1][j],t[i][j-1]);
              }
          }
      }  
       return t[len][len]; 
    }
};