class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // no swap is also available count==0
        // find places where differ and count
        int count=0;//should not exceed 2
        int a=-1,b=-1;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(a==-1){
                    a=i;
                }
                else{
                    b=i;
                }
                count++;
            }
        }
        if(count==0){
            return true;
        }
        else if(count==2&&s1[a]==s2[b]&&s1[b]==s2[a]){
            return true;
        }
        else {
            return false;
        }
    return false;
    }
};