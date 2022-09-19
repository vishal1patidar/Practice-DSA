class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int result = numeric_limits<int>::max(), total = 0, windowStart = 0;
    for (int windowEnd = 0; windowEnd < nums.size();) {
		// It is a waste of time to continue if a single number is already our target
        if (nums[windowEnd] >= target) {
            return 1;
        }

		// Add current number to the total
        total += nums[windowEnd];

		// If the current total is our target
        if (total >= target) {
			// Save the minimum sliding window found since now
            result = min(windowEnd - windowStart + 1, result);

			// Remove the first and the last number of the window from the total
            total -= nums[windowStart];
            total -= nums[windowEnd];

			// Increment the sliding window starting point
            windowStart++;
        } else {
			// Increment the sliding window ending point
            windowEnd++;
        }
    }

	// If the result isn't changed, we haven't found the target!
    if (result == numeric_limits<int>::max()) {
        result = 0;
    }

    return result;
    }
};