class Solution {
public:
    double average(vector<int>& v) {
        int mi = min_element(v.begin(), v.end()) - v.begin();
        int ma = max_element(v.begin(), v.end()) - v.begin();
        int n = v.size();        
        double ans = 0;
        for (int i=0 ; i<n ; i++)
        {
            if (i != mi && i != ma)
                ans += v[i];
        }
        
        return ans/(n-2);
    }
};