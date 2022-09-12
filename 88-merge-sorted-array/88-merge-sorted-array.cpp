class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1,j=n-1;
        int curIdx=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]<=nums2[j]){
                nums1[curIdx]=nums2[j];
                j--;
                curIdx--;
            }
            else{
                nums1[curIdx]=nums1[i];
                i--;
                curIdx--;
            }
        }
        if(i<0){
            for(int t=0;t<=j;t++){
                nums1[t]=nums2[t];
            }
        }
    }
};