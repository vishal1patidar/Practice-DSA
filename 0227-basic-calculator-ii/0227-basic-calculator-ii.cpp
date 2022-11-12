// class Solution {
// public:
//     int calculate(string s) {
//         stack<int> st;
//         int n = s.size(), ans = 0, current = 0;
        
//         for(int i=0; i<n-1; i++){
//             if(s[i] == ' ') continue;
//             else if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/'){
//                 current = (s[i]-'0');
//                 st.push(current);
//             }
//             else{
//                 current =  current*10 + (s[i+1]-'0');
//                 if(s[i] == '+'){
//                     st.push(current);
//                     i++;
//                 } 
//                 else if(s[i] == '-'){
//                     st.push(-1 * (current));
//                     i++;
//                 } 
//                 else if(s[i] == '*'){
//                     int a = st.top()*current;
//                     st.pop();
//                     st.push(a);
//                     i++;
//                 } 
//                 else if(s[i] == '/'){
//                     int a = st.top()/current;
//                     st.pop();
//                     st.push(a);
//                     i++;
//                 } 
//             }
//             current = 0;
//         }
//         while(!st.empty()){
//             ans += st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        s += '+';
        int n = s.size(), ans = 0, current = 0;
        char sign = '+';
        
        for(int i=0; i<n; i++){
            
            if(isdigit(s[i])) current = current*10 + (s[i]-'0');
            
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                if(sign == '+'){
                    st.push(current);
                } 
                else if(sign == '-'){
                    st.push(-1 * (current));
                } 
                else if(sign == '*'){
                    int a = st.top();
                    st.pop();
                    st.push(a*current);
                } 
                else if(sign == '/'){
                    int a = st.top();
                    st.pop();
                    st.push(a/current);
                } 
                current = 0;
                sign = s[i];
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};