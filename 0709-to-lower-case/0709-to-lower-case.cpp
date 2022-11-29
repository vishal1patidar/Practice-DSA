class Solution {
public:
    string toLowerCase(string s) {
       string str = "";
    char c;
    for(int i = 0; i<s.size(); i++){
        c = s[i];
        if(s[i]>='A' && s[i]<='Z'){
            c = (c-'A') + 'a';
            str += c;
        }
        else 
            str+= c;
    }
    return str;
}
}; 
  