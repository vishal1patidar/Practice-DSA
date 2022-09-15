class Solution {
public:
     int maxSubarraySumCircular(vector<int>& nums) {
      int min = INT_MAX, max = INT_MIN;
      int s1 = 0, s2 = 0, s = 0;
      for(auto i : nums) {
        s += i; // sum of all elements
        
        // maximum sum
        s1 += i;
        if(s1 > max) max = s1;
        if(s1 < 0) s1 = 0;
        
        //minimum sum
        s2 += i;
        if(s2 < min) min = s2;
        if(s2 > 0) s2 = 0;
    }
    
    if(max < 0) return max;
    return max > s - min ? max : s - min;
}
  
};