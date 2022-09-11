class Solution {
public:
    
    
    void solve(string s,string &op,vector<string>&ans){
        
        if(s.length()==0){
            ans.push_back(op);
            return;
        }
        
        
        //as it is :-
        string op1 = op;
        string op2 = op;
        
        op1.push_back(s[0]);
        
        char temp = s[0];
        s.erase(s.begin()+0);
        
        //if s[0] is not a number :- 
        if((temp >= 97 && temp<=122) || (temp>=65 && temp<=90)){
            if(temp>=97)op2.push_back(temp-32);
            else op2.push_back(temp+32);
            solve(s,op2,ans);
        }
        
        solve(s,op1,ans);
    }
    
    vector<string> letterCasePermutation(string s) {
     vector<string>ans;
        // if(s.length()==0)return ans;
        string op = "";
        solve(s,op,ans);
        return ans;
    }
};