class Solution {
public:
    int maxCnt=0,currCnt=0;
    int helper(vector<int>&nums,int target){
       int cnt=0;
       int low=0,high=nums.size()-1;
       while(low<=high && target!=0){
           if(target-nums[low]>=0){
               target-=nums[low];
               low++;
           }
           else if(target-nums[high]>=0){
                target-=nums[high];
                high--;
           }
           else return cnt;
           cnt++;
       }
       return cnt;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=helper(nums,queries[i]);
        }
        return ans;
    }
};