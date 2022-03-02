class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(s.size() > t.size())  // one corner case
        {
            return false;
        }
        int i=0;// pointing string s
        int j=0;// pointing string t
        
        while(i<s.size() and j < t.size())
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        
        if(i == s.size())
        {
            return true;
        }
        return false;   
    }
};