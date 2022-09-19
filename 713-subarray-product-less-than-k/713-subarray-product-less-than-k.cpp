class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if(k <= 1) return 0;
            int i = 0;
            int j = 0;
            int prod = 1;
            int ans = 0;
            while (j < nums.size())
            {

                prod *= nums[j]; // updating our prod everytime 
                
                if (prod < k)
                {
                    ans += j-i+1;
                    j++;
                }
                if (prod >= k)
                {

                    while (prod >= k)
                    {
                        
                        prod /= nums[i];
                        i++;
                    }
                    ans += j-i+1;
                    j++;
                }
            }

            return ans;
    }
};
