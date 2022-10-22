class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() or s.empty()) {
            return "";
        }
        
        int i = 0, j = 0;
        int start = -1, len = INT_MAX;
        std::vector<int> m(128, 0);
        
        // Push elements of t into hash table.
        for (auto c : t) {
            m[c]++;
        }
        
        while (j < s.size()) {
            if (isFound(m)) {
                // Current string contains all characters of t,
                // then we start to shrink it from left.
                if (j - i < len) {
                    start = i;
                    len = j - i;
                }
                m[s[i++]]++;
                continue;
            }
            // Current string doesn't contain all characters of t,
            // so we need to extend it and do checking in the next iteration.
            m[s[j++]]--;
        }
        
        // Try to shrink the last found string.
        while (isFound(m)) {
            if (j - i < len) {
                start = i;
                len = j - i;
            }
            m[s[i++]]++;
        }
        
        if (start != -1) {
            return s.substr(start, len);
        }
        return "";
    }

private:
    // If all values of hash table are <= 0,
    // it means all characters of t are included in current string
    bool isFound(const std::vector<int>& m) {
        return std::all_of(m.begin(), m.end(), [](int i) { return i <= 0; });
    }
};