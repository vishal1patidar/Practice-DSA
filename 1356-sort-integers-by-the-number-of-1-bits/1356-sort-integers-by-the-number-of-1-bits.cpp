class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> bits;
        vector<int> ans;
        
        int n = arr.size();
        
		// step-1
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            int x = arr[i];
			// Brian Kernighan’s Algorithm to find set bit of a number
            while(x) {
                x &= (x-1);
                cnt++;
            }
            bits.push_back({cnt, arr[i]});
        }
		
        // step-2
        sort(bits.begin(), bits.end());
		
		//step-3
        for(int i = 0; i < n; i++) {
            ans.push_back(bits[i].second);
        }
        
        return ans;
    }
};