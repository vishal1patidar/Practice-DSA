class Solution {
public:
    int dp[1001];
    int solve(string s,int idx){
        if(idx==s.length()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        int way1 = solve(s,idx+1);
        int way2=0;
        int num=stoi(s.substr(idx,2));
        if(idx<s.length()-1 && num<=26){
            way2 = solve(s,idx+2);
        }
        return dp[idx] = way1 + way2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};