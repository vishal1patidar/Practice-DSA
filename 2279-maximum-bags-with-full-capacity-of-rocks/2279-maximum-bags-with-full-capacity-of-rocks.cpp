class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int n = rocks.size();
        vector<int> v;
        
        // storing the diff of cap-roc (max rocks that i cam put in bag now)
        for(int i=0;i<n;i++)
        {
            v.push_back(capacity[i]-rocks[i]);
        }
        
        // 1,1,0,1
        // 0,1,1,1
        sort(v.begin(),v.end());
        
        // now i am having additionalRocks and I'll try to put those into the bags and check how many bangs can be full
        for(int i=0;i<n;i++)
        {
            // if curr bag is not full and I can put bricks into it from additionalRocks
            if(v[i]!=0 && v[i]<=additionalRocks)
            {
                additionalRocks = additionalRocks-v[i];                         // reduce the taken bricks
                v[i] = 0;                                                       // after taking the bricks current bag will be full
                if(additionalRocks<=0) break;                                   // any time if my additionalRocks goes <=0 if means just stop
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            // couting the bags that are full
            if(v[i]==0) cnt++;
        }
        return cnt;
    }
};