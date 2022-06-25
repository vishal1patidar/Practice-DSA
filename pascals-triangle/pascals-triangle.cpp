class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        nums.push_back(vector<int> (1,1));
        if (numRows == 1)
            return nums;
        nums.push_back(vector<int> (2,1));
        if (numRows == 2)
            return nums;
        int cnt = 2;
        while(cnt < numRows){
            vector<int> out(cnt+1);
            out[0] = 1;
            out[out.size()-1] = 1;
            for (int i=0;i<nums[cnt-1].size()-1;i++ ){
                out[i+1] = nums[cnt-1][i] + nums[cnt-1][i+1];
            }
            nums.push_back(out);
            cnt = cnt+1;
        }
            
        return nums;
    }
};