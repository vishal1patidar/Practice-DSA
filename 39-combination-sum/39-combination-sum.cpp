// class Solution {
// public:
//     vector<vector<int>> ans; // 2 D vector to store our answer
//     void solve(int i, vector<int>& arr, vector<int>& temp, int target)
//     {
//         // if our target becomes zero at any point, then yess!! we wil find a possible combination
//         if(target == 0) 
//         {
//             ans.push_back(temp); // include that combination in our answer
//             return; // and then return, we are now not gonna explore more possiblity
//         }
        
//         // if at any point target becomes less than zero, then simply return, saying that no it is notpossible to our target combination sum
//         if(target < 0)
//             return;
        
//         // if index crosses the last index, we will return saying that no more element is left to choosee
//         if(i == arr.size())
//             return;
        
//         // As we dicussed for every element we have two choices whether to include in our answer or not include in our answer. 
// 		//so now, we are doing that
        
//         // we are not taking the ith element,
//         // so without decreasing sum we will move to next index because it will not contribute in making our sum
//         solve(i + 1, arr, temp, target);
        
//         // we are taking the ith element and not moving onto the next element because it may be possible that this element again contribute in making our sum.
//         // but we decrease our target sum as we are consediring that this will help us in making our target sum
        
//         temp.push_back(arr[i]); // including ith element
//         solve(i, arr, temp, target - arr[i]); // decreasing sum,and call again function
//         temp.pop_back(); // backtrack
        
//     }
//     vector<vector<int>> combinationSum(vector<int>& arr, int target) {
//         ans.clear(); // clear global array, make to sure that no garbage value is present in it
        
//         vector<int> temp; // temporary vector that tries all possible combination
        
//         solve(0, arr, temp, target); // calling function, and see we start from index zero
        
//         return ans; // finally return the answer array
//     }
// };
// Solution - II (using Recursion, Accepted)-

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