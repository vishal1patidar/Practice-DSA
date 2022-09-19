class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int mx= (r-l)*min(height[l],height[r]);
        while(l<r){
            
            height[l]>height[r]?r--:l++;
            mx=max((r-l)*min(height[l],height[r]),mx);
        }
        
        return mx;
    }
};