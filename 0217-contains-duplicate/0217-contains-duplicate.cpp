class Solution {
public:
    bool containsDuplicate(vector<int>& vec) {
        unordered_set<int> st;
        for(auto i : vec) {
            if(st.find(i) != st.end()) return true;
            st.insert(i);
        }
        return false;
    }
};