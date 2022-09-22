class Solution {
public:
    string decodeString(string s) {
        stack<string> s1;
        stack<int> s2;
        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i])){
                int ind = i, fact = 0;
                while(isdigit(s[ind])){
                    fact = fact*10 + (s[ind]-'0'); ind++;
                }
                s2.push(fact);
                i = ind-1;
            }else if(s[i]=='[' || isalpha(s[i])){
                string temp(1,s[i]);
                s1.push(temp);
            }else{
                int ind = i;
                string combine = "";
                while(s1.top()!="["){
                    string top = s1.top();
                    s1.pop();
                    combine = top + combine;
                }
                string temp_string = "";
                int k = s2.top(); s2.pop();
                while(k--) temp_string += combine;
                s1.pop();
                s1.push(temp_string);
            }
        }
        string answer = "";
        while(!s1.empty()){
            answer = s1.top() + answer;
            s1.pop();
        }
        return answer;
    }
};