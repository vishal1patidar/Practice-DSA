class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
		//Vector to store left side product of an element.
        vector<int> lp(n,0);
		//Nothing is there in leftside of first element.
        lp[0]=1;
        
		//Traversing to get the all left products
        for(int i=1;i<n;i++){
            lp[i]=lp[i-1]*nums[i-1];
        }
        
		//Traversing using a variable to reduce using another vector.
        int r=1;
        for(int i=n-1;i>=0;i--){
            lp[i]=lp[i]*r;
            r*=nums[i];
        }
        
        return lp;
    }
};