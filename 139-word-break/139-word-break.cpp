class Solution {
public:
    bool fun(int lo, int hi, string s, unordered_set<string> &st, vector<vector<int>> &dp){
        if(lo == 0){
            if(st.find(s.substr(lo, hi - lo + 1)) != st.end()){
                return true;
            }else{
                return false;
            }
        }
        if(dp[lo][hi] != -1){
            return dp[lo][hi];
        }
        
        string str = s.substr(lo, hi - lo + 1);
        if(st.find(str) != st.end()){
            bool notBreak = fun(lo - 1, hi, s, st, dp);
            bool Break = fun(lo - 1, lo - 1, s, st, dp);
            return dp[lo][hi] = notBreak || Break;
        }else{
            bool notBreak = fun(lo - 1, hi, s, st, dp);   
            return dp[lo][hi] = notBreak;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        vector<vector<int>> dp(slen, vector<int>(slen, -1));
        return fun(slen - 1, slen - 1, s, st, dp);
    }
};