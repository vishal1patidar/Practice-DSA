class Solution {
public:
    static bool comp(pair<string , int>& p1 , pair<string , int>& p2){
        if(p1.second < p2.second){
            return true;
        }else if(p1.second > p2.second){
            return false;
        }else{
            if(p1.first > p2.first){
                return true;
            }else{
                return false;
            }
        }
    }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {    
        unordered_map<string , int> mp;
        for(int i = 0 ; i < words.size() ; i++){
            mp[words[i]]++;
        }
        
        vector<pair<string , int>> hash_list;
        
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            hash_list.push_back({it->first , it->second});
        }
        
        sort(hash_list.begin() , hash_list.end() , comp);
        reverse(hash_list.begin() , hash_list.end());
        
        vector<string> ans;
        for(int i = 0 ; i < k ; i++){
            ans.push_back(hash_list[i].first);
        }
        
        return ans;
        
    }
};