class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans=0;
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>a,vector<int>b){
            return a[1]>b[1];
        });
        int i=0;
        while(truckSize>0&&i<boxTypes.size()){
            
            if(boxTypes[i][0]>truckSize){
                ans+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
            else{
                ans+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            i++;
        }
        return ans;
    }
};