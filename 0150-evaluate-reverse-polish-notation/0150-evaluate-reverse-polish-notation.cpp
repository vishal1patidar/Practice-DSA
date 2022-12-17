#include <bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <long> s;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "*" || tokens[i] == "/" 
            || tokens[i] == "+" || tokens[i] == "-"){
                long op1, op2;
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                if(tokens[i] == "*"){
                    s.push(op1 * op2);
                }
                else if(tokens[i] == "/"){
                    s.push(op1 / op2);
                }
                else if(tokens[i] == "+"){
                    s.push(op1 + op2);
                }
                else{
                    s.push(op1 - op2);
                }
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};