class Solution {
public:
int numberOfArithmeticSlices(vector<int>& nums) {
if(nums.size()<=2)
return 0;

    int ans=0;
    int cnt=0;
    for(int i=1;i<nums.size()-1;i++)
    {
        if(nums[i-1]-nums[i]==nums[i]-nums[i+1])
            ans++;
        else
            ans=0;
        cnt+=ans;
    }
    
   
    
    
    return cnt;
}
};