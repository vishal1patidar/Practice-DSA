class Solution {
public:
    void helper(int n,int open,int close,string str,vector<string> &ans)
    {
        if(open > n)
            return;
        if(open == n && close == n)
        {
            ans.push_back(str);
            return;
        }
        
        helper(n,open+1,close,str+'(',ans);
        
        if(open > close)
            helper(n,open,close+1,str+')',ans);
        
    }
    vector<string> generateParenthesis(int n) 
    {
        string str = "";
        vector<string> ans;
        helper(n,0,0,str,ans);
        return ans;
           
    }
};