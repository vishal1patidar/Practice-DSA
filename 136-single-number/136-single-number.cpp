class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size(); // taking the size of the array 
        
        unordered_map<int, int> mp; // unordered map to store the frequency
        
        // storing frequency in the map
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        
        int ans; // variable to store our answer
        for(auto x: mp) // traverse from the map
        {
            if(x.second == 1) //if frequency of any elemennt is 1
            {
                ans = x.first; // store in our answer
                break; // break the loop, as we got our answer now
            }
        }
        
        return ans; // return ans
    }
};