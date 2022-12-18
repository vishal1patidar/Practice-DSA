class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(),0);
        stack<pair<int,int>> mys;
        for(int i=0;i<temperatures.size();i++){
            while(!mys.empty()){
                pair<int,int> pt=mys.top();
                if(temperatures[i]>pt.second){
                    ret[pt.first]=i-pt.first;
                    mys.pop();
                }else{
                    break;
                }
            }
            mys.push(make_pair(i,temperatures[i]));
        }
        return ret;
    }
};