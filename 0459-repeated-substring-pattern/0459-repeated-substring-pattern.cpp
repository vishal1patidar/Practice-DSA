class Solution {
public:
    bool can_make(string &key, string &s){
        int sub = key.length();
        
         for(int i{sub}; i < s.length(); i += sub)
            if(s.substr(i, sub) != key)
                return false;
        
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        int right{1};
        string key{s[0]};
        
        while(right <= (n / 2)){  
            if(n % right == 0){
                if(can_make(key, s)) // If key can make s
                    return true;
            }
            
            key.push_back(s[right]);
            
            right++;
        }
        
       return false;
    }
};