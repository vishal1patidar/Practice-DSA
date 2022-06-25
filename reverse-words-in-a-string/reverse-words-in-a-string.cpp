class Solution {
public:
    string reverseWords(string s) {
         vector<string> ans;
        string res="";
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]!=' ')
            {
                res+=s[i];
            }
            else if(s[i]==' ' && res.length()>0)
            {
                ans.push_back(res);
                res.clear();
            }
        }
        
        if(res.length()!=0)
        {
            ans.push_back(res);
        }
        
        reverse(ans.begin(), ans.end());
        string x="";
        
        for(int i=0;i<ans.size()-1;i++)
        {
            x=x+ ans[i]+" ";
        }
        
        x+= ans[ans.size()-1];
        
        return x;
    }
};