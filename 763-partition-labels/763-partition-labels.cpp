class Solution {
public:
    vector<int> partitionLabels(string S) {
       vector<int> ans;
        for (int i = 0, start = 0, end = 0; i < S.length(); i++) {
            end = max(end, (int)S.find_last_of(S[i]));
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans; 
    }
};