class Solution {
public:
    string getHint(string secret, string guess) {
      map<char,int>mp;
        int cnt=0,c=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                cnt++;
            mp[secret[i]]++;
        }
        for(int i=0;i<guess.size();i++){
            if(mp.find(guess[i])!=mp.end() and mp[guess[i]]>0){
                mp[guess[i]]--;
                c++;
            }
        }
        string s="";
        string s2,s1=to_string(cnt);
        s2=to_string(c-cnt);
        s+=s1;
        s+='A';
        s+=s2;
        s+='B';
        return s;
    }

};