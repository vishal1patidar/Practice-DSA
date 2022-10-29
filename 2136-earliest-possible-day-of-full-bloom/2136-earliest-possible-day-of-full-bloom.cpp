class Solution {
public:
   static bool comp(pair<int,int>p1,pair<int,int>p2){
     
     return p1.second > p2.second;
 }
int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    
         int res=0;
         int start=0;
      vector<pair<int,int>> aux;
    
    for(int i=0;i<plantTime.size();i++)
    aux.push_back({plantTime[i],growTime[i]});
    
    sort(aux.begin(),aux.end(),comp);
    
    for(int i=0;i<plantTime.size();i++){
        
        start += aux[i].first;
         res=max(res,start + aux[i].second);
    }
    
    
    return res;
}
};