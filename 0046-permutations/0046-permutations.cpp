class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        for (int i = 0, n = factorial(nums.size()); i < n; i++) {
            perms.push_back(nums);
            nextPermutation(nums);
        }
        return perms;
    }
private:
    int factorial(int n) {
        int f = 1;
        while (n > 1) {
            f *= n--;
        }
        return f;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
