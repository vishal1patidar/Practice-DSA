#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>a(101);
        vector<int>b(101);
        int n=nums.size();
        for(int i=0;i<n;i++)  
            a[nums[i]]++;
        for(int i=1;i<101;i++) 
            b[i]=b[i-1]+a[i-1];
        vector<int>ans(n);  
        for(int i=0;i<n;i++){
            ans[i]=b[nums[i]];
        }
        return ans;
    }
};