class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& lastList) {
        int i=0;
        int j=0;
        int mini;
        int maxi;
        vector<vector<int>> ans;
        while(i<firstList.size() && j<lastList.size())
        {
            maxi=max(firstList[i][0],lastList[j][0]);
            mini=min(firstList[i][1],lastList[j][1]);
            if((mini-maxi)>=0)
            {
                ans.push_back({maxi,mini});
            }
            if(firstList[i][1]<lastList[j][1])
            {
                i++;
            }
            else
                j++;
        }
        return ans;
    }
};