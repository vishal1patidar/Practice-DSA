class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        int ans_len = 0;
        for(int i=0; i<n; i++)
        {
            int l = i, r =i;  //odd size length eg: bab
            while(l>=0 && r<n && s[l]==s[r])
            {
                if((r-l+1)>ans_len)
                {
                    ans = s.substr(l, r-l+1);
                    ans_len = r-l+1;
                }
                l--;
                r++;
            }
            l =i, r = i+1;  //even size length eg: baab
            while(l>=0 && r<n && s[l]==s[r])
            {
                if((r-l+1)>ans_len)
                {
                    ans = s.substr(l, r-l+1);
                    ans_len = r-l+1;
                }
                l--;
                r++;
            }
        }
        return ans; 
    }
};