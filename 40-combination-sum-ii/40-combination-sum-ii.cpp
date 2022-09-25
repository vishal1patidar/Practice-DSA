class Solution {
public:
    void find(vector<int> arr, vector<vector<int>>& ans, vector<int>& output, int target, int index){
    if(target==0){
        ans.push_back(output);
        return ;
    }
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]<=target){
            output.push_back(arr[i]);
            find(arr, ans, output, target-arr[i], i+1);
            output.pop_back();
        }
    }        
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> output;
    find(candidates, ans, output, target, 0);
    return ans;
}
};