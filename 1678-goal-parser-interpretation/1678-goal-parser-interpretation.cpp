class Solution {
public:
    string interpret(string c) {
        string str="";
        for(int i=0;i<c.size();i++)
        {
            if(c[i]=='G')
                str+="G";
            if(c[i]=='(' && c[i+1]==')')
                str+="o";
            if(c[i]=='(' && c[i+1]=='a')
                str+="al";
        }
        return str;
    }
};