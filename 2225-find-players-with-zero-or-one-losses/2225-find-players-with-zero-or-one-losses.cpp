class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> losses;
        for(vector<int> v:matches){
            int x = v[0],y = v[1];
           if(losses.count(x)==0)losses[x]=0;
           losses[y]++;
        }
        vector<int> noLoss,oneLoss;
        for(auto it: losses){
            if(it.second ==0){
                noLoss.push_back(it.first);
            }
            else if(it.second == 1){
                oneLoss.push_back(it.first);
            }
        }

         return {noLoss,oneLoss};
  
    }
};