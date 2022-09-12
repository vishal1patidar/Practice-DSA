class Solution {
public:
int longestPalindrome(string s) {
int ar[58];
int cnt=1;
memset(ar,0,sizeof(ar));
for(int i=0;i<s.size();i++)
{
ar[s[i]-'A']++;
}

    for(int i=0;i<58;i++)
    {
        if(ar[i]>1)
        {
            ar[i]/=2;
            ar[i]*=2;
            cnt+=ar[i];
        }
    }
    if(cnt>s.size())
    return cnt-1;
    else
        return cnt;
}
};