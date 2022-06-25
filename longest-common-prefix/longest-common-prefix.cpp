class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
       
       int n = strs.size();
       
   	//storing first and last strings in a and b
       string a = strs[0];
       string b = strs[n - 1];
       
       int i = 0;
       
       while (i < a.size() && i < b.size() && a[i] == b[i])
       {
           i++;
       }
       
       return a.substr(0, i);
    }
};