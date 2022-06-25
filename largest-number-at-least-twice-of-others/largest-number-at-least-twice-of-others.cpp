class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int m=*max_element(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++){
			if(m<2*nums[i] && nums[i]!=m)return -1;
		}
		for(int i=0;i<nums.size();i++){
			if(nums[i]==m)return i;
		}
		return 0;
	}
};