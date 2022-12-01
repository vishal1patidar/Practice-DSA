class Solution {
public:
    bool halvesAreAlike(string s) {
        string a,b;
        int cnt1 =0, cnt2=0;
        for(int i = 0; i < s.length()/2; ++i)
        {
            a.push_back(s[i]);
        }
        for(int i = s.length()/2; i < s.length(); ++i)
        {
            b.push_back(s[i]);
        }
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] == 'a' || a[i] == 'A' || a[i] == 'e' || a[i] == 'E' || a[i] == 'i' || a[i] == 'I' || a[i] == 'o' || a[i] == 'O' || a[i] == 'u' || a[i] == 'U')
            {
               cnt1++; 
            }
        
            if(b[i] == 'a' || b[i] == 'A' || b[i] == 'e' || b[i] == 'E' || b[i] == 'i' || b[i] == 'I' || b[i] == 'o' || b[i] == 'O' || b[i] == 'u' || b[i] == 'U')
            {
                cnt2++;
            }

        }
        
      if(cnt1 == cnt2)
      {
          return true;
      }
      return false;
    }
};