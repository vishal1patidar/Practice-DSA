class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)
            return {};
     unordered_map<string,int>mp;
      vector<string>ans;
        int i=s.size()-1;
        int j=s.size()-1;
        int k=10;
        string substr="";
        // create a window
        while(i-j+1<k)
        {
            substr=s[j]+substr;
            j--;
        }
        
        while(j>=0)
        {
            //calculation
            substr=s[j]+substr;
            if(mp[substr]!=-1)
             mp[substr]++;
            
            //  To stroe result
            if(mp[substr]>1)
            {ans.push_back(substr);mp[substr]=-1;}
            
            // Remove calculation for i
            substr.resize(k-1);
            // Slide the window
            i--;
            j--;
            
                
                
        }
      return ans;
    }
};
