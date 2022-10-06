class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<int, string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!m.count(key))
            return "";
        int start = 0, end = m[key].size();
        while(start < end) {
            int mid = start + (end-start)/2;
            if(m[key][mid].first > timestamp)
                end = mid;
            else
                start = mid + 1;
        }
        return start > 0 and start <= m[key].size() ? m[key][start-1].second : "";
    }
};
