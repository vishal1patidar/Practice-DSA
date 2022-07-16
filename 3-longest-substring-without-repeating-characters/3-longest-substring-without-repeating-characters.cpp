class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //record the appearence conditions of the elements
        vector<int> record(128, -1); 
        
        int ans = 0;
        
        //record the index of the newest repeated element 
        //start from -1 since for the 0th element : 0-(-1)=1
        int newestRepeated = -1;
        
        for(int i = 0; i < s.size(); i++){
            //this element has already appeared 
            if(record[s[i]] != -1) {
                //update the index of the newest repeated element
                newestRepeated = max(newestRepeated, record[s[i]]);
            }
            
            //compare the length of the current substring with the current longest substring 
            ans = max(ans, i-newestRepeated);
            
            //update the newest appearence of this element
            record[s[i]] = i; 
        }
        
        return ans;
    }
};