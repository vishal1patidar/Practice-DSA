class Solution {
public:
    void backTrack(int n,int k,int it,vector<vector<int>> &ans,vector<int> &res){
        
        if(res.size()==k){
            ans.push_back(res);
            return;
        }
        for(int i=it;i<=n;i++){
            res.push_back(i);
            backTrack(n,k,i+1,ans,res);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        backTrack(n,k,1,ans,res);
        return ans;
    }

};