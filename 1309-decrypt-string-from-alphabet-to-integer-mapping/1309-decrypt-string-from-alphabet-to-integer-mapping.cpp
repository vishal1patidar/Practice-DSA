class Solution {
public:
   string freqAlphabets(string s) {
        int i = s.length()-1, st;
        string ans="";
        while(i>=0){
            if(s[i]=='#')
                st = stoi(s.substr(i-2, 2)), i-=3;
            else
                st = (s[i]-'0'), i--;
            ans = char(96+st)  + ans;
        }
        return ans;
    }
};