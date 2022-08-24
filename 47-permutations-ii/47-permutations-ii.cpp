class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>  &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> permutations({nums});
        int n = static_cast<int>(nums.size()), i = n - 1;
        while(i > 0) {
            for (i = n - 1; i > 0; --i) {
                if (nums[i - 1] >= nums[i]) continue;
                for (int j = n - 1; j >= i; --j) {
                    if (nums[i - 1] >= nums[j]) continue;
                    std::swap(nums[j], nums[i - 1]);
                    std::reverse(nums.begin() + i, nums.end());
                    permutations.emplace_back(nums);
                    break;
                }
                break;
            }
        }
        return permutations;
    }
};