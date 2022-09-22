class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
       priority_queue<int> p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        
        
       while(p.size()>1){
           int x=p.top();
           p.pop();
           int y=p.top();
           p.pop();
           p.push(abs(x-y));
       }
        
        return p.top();
        
    }
};