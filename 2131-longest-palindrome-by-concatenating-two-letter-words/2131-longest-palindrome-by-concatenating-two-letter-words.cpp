class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int maxi = 0;
        int res = 0;
        bool flag = 0;
        unordered_map<string,int>mpp1,mpp2;

        for(auto &it : words)
        {
           if(it[1]==it[0]) mpp1[it]++;
              
           else  mpp2[it]++;
               
        }
        
        for(auto &it : mpp2)
        {
            string r = it.first;
            reverse(r.begin(),r.end());

            if(mpp2.find(r) != mpp2.end() && mpp2[r] > 0 && it.second > 0)
            {
               res += 4 * min(mpp2[r],it.second);
               mpp2[r] = -1;
               mpp2[it.first] = -1;
              
            }
        }
 
        for(auto &it : mpp1)
        {
            if(it.second % 2==0)  res += it.second * 2;
            
            else
            {
                 flag = 1;
                 res += (it.second-1) * 2;
            }
        }
        
       if(flag) res += 2;
       
       return res;
    }
};
