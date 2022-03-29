// 1. Easy C++
// 2. Line by Line Explanation with Comments.
// 3. Detailed Explanation ✅
// 4. Initution is to use Binary Search for (logn) compexity ,
//    other approaches are using map, bruteforce, cnt vector.
// 5. Please Upvote if it helps⬆️
// APPROACH 1 USING BINARY SEARCH
// ALGORITHM

// Perform Binary Search on range 1 to n;
// low = 1, high = nums.size() - 1;
// While the value of high is greater than or equal to low.
// calculate mid.
// count elements <= to mid.
// if count is less than equal to mid.
// low = mid + 1 (binary search on right half)
// else high = mid + 1 (binary search on left half)
// Return low which will point to duplicate.


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
	// for github repository link go to my profile.
};