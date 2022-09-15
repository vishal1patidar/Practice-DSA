class Solution {
public:
int findMin(vector<int>& nums) {
int res=0;
res=*min_element(nums.begin(),nums.end());
return res;

}
};