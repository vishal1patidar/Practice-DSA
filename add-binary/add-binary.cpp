class Solution {
public:
    string addBinary(string a, string b) {
        int len1=a.length();
        int len2=b.length();
        int mn=min(len1,len2);
        int carry=0;
        int i=len1-1;
        int j=len2-1;
        string ans="";
        while(mn--)
        {
             int a1=a[i--]-'0';
            int a2=b[j--]-'0';
            if(a1==1&&a2==1)
            {
                if(carry)
                {
                    ans=ans+'1';
                    carry=1;
                }
                else{
                    ans=ans+'0';
                    carry=1;
                }
            }
            else{
                
                int total=a1+a2;
                
                if(total==0)
                {
                    if(carry)
                    {
                        ans=ans+'1';
                        carry=0;
                    }
                    else{
                        ans=ans+'0';
                    }
                }
                else if(total==1)
                {
                    if(carry)
                    {
                        ans=ans+'0';
                        carry=1;
                    }
                    else{
                        ans=ans+'1';
                    }
                }
                
            }
          
        }
        while(i>=0)
        {
            int a1=a[i--]-'0';
            if(a1==1)
            {
                if(carry)
                {
                    ans=ans+'0';
                    carry=1;
                }
                else{
                    ans=ans+'1';
                }
            }
            else{
                if(carry)
                {
                    ans=ans+'1';
                    carry=0;
                }
                else{
                    ans=ans+'0';
                }
            }
        }
        while(j>=0)
        {
              int a1=b[j--]-'0';
            if(a1==1)
            {
                if(carry)
                {
                    ans=ans+'0';
                    carry=1;
                }
                else{
                    ans=ans+'1';
                }
            }
            else{
                if(carry)
                {
                    ans=ans+'1';
                    carry=0;
                }
                else{
                    ans=ans+'0';
                }
            }
        }
        
     if(carry)
     {
         ans=ans+'1';
     }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};