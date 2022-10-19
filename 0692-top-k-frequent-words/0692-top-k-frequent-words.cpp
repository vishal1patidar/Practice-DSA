class Solution {
public:
    static bool comp(pair<int,string> &a,pair<int,string> &b)
    {
        if(a.first!=b.first) return a.first>b.first;
        else return a.second<b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        vector<pair<int,string>> pq;
        for(auto &it:mp)
        {
            pq.push_back({it.second,it.first});
        }
        sort(pq.begin(),pq.end(),comp);
        vector<string> ans;
        for(int i=0;i<pq.size();i++)
        {
            if(k)
            {
                ans.push_back(pq[i].second);
                k--;
            }
        }
        return ans;
    }
};