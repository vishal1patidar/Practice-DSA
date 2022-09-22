class Solution {
public:
    struct hashFunction 
{
  size_t operator()(const vector<int> 
                    &myVector) const 
  {
    std::hash<int> hasher;
    size_t answer = 0;
      
    for (int i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};
    unordered_set<vector<int>,hashFunction>mt;
    void sub(vector<int>&nums,int i,vector<int>temp){
        if(i==nums.size()){
            sort(temp.begin(),temp.end());
            mt.insert(temp);
            return;
        }
        sub(nums,i+1,temp);
        temp.push_back(nums[i]);
        sub(nums,i+1,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sub(nums,0,temp);
        vector<vector<int>>ans;
         for (auto itr = mt.begin(); itr != mt.end(); itr++)        ans.push_back((*itr));
        return ans;
        
    }
};