class Solution {
public:
     vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        vector<vector<int>> freq(nums.size()+1);
        vector<int> ans;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            umap[nums[i]]++;
        }
        for(auto e:umap){
            freq[e.second].push_back(e.first);
        }
        for(int i=nums.size(); i>0; i--){
            if(freq[i].size()!=0){
                for(int j=0; j<freq[i].size(); j++){
                    ans.push_back(freq[i][j]);
                    count++;
                }
            }
            if(count==k) break;
        }
        return ans;
    }
};