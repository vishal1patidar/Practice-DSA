
class Solution {
public:
    // for the sake of convience, not to include again and again in my function call, I declare target here
    int target;
    
    vector<vector<int>> ans; // 2-D vector to store our answer
    
    void solve(vector<int>& arr, int i, int sum, vector<int> op)
    {
        // if i crosses the array size, we will return saying that no more possibilty is left to choose
        
        if(i >= arr.size()) 
        {
            return;
        }
        
        // if value at ith index + sum becomes equal to target, then we will store it in our answer array, saying that yes it is a possible combination
        if(arr[i] + sum == target)
        {
            op.push_back(arr[i]);
            ans.push_back(op);
            return;
        }
        
        // if value at ith index + sum is less than target, then we have two choices i.e whether to include this value in our possible combiation array or not include that,
        if(arr[i] + sum < target)
        {
            // we make two output vector, one for calling function at same index and anthor for calling function frm next index. Because for every element we have unlimited choices, that it will contribute in making our sum any number of times.
            vector<int> op1 = op;
            vector<int> op2 = op;
            
            op2.push_back(arr[i]);
            solve(arr, i, sum + arr[i], op2);
            solve(arr, i + 1, sum, op1);
        }
        else
        {
            solve(arr, i + 1, sum, op); // call for the next index
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int required_target) {
        ans.clear(); //clear global array, make to sure that no garbage value is present in it
        
        target = required_target; // give target what he wants 
        vector<int> op; // op array to try all possible combination
        sort(arr.begin(),arr.end()); // sort the array in ascending order
        solve(arr, 0, 0, op); // call function
        
        return ans; // return the final answer array
    }
};