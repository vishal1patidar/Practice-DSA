class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int val=1;
        for (int i=0; i<arr.size(); i++){
            if (arr[i]!=val){
                k--;
                --i;
            }
            if (k==0)return val;
            val++;
        }
        while(k>1){
            val++;
            k--;
        }
        return val;
    }
};