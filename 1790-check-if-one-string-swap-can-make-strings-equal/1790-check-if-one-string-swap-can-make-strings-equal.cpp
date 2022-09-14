//TC-O(n)
//SC-O(n)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       unordered_map<char,int>m1,m2;
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
            m1[s1[i]]++; 
        }
        for(int i=0;i<s2.size();i++){
           
            m2[s2[i]]++; 
        }
        if((cnt==2 || s1==s2) && m1==m2){
            return true;
        }
        return false;
    }
};