class Solution {
public:
    
    void insertHelper(priority_queue<pair<int, int>> &pq, vector<int> &arr, int k, int x, int l, int r){
        if(l != 0){
            //need to insert lth val
            if(pq.size()<k){
                pq.push({abs(arr[l]-x), arr[l]});
                return;
            } else {
                if(abs(pq.top().first)>abs(arr[l]-x)){
                    pq.pop();
                    pq.push({abs(arr[l]-x), arr[l]});
                }
            }
        } else {
            //need to insert rth val
            if(pq.size()<k){
                pq.push({abs(arr[r]-x), arr[r]});
                return;
            } else {
                if(abs(pq.top().first) >= abs(arr[r]-x)){
                    pq.pop();
                    pq.push({abs(arr[r]-x), arr[r]});
                }
            }
        }
    }
    
    vector<int> generateAns(priority_queue<pair<int, int>> &pq){
        vector<int> ans(pq.size());
        int ind = pq.size()-1;
        while(!pq.empty()){
            ans[ind] = pq.top().second;
            pq.pop();
            ind--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == 1)
            return arr;
        
        int l  = 0, r = arr.size()-1;
        priority_queue<pair<int, int>> pq;
        
        while(l<=r){
            int val1 = abs(arr[l]-x);
            int val2 = abs(arr[r]-x);
            if(val1 > val2){
               insertHelper(pq, arr, k, x, 0, r);
               r--; 
            } else {
                insertHelper(pq, arr, k, x, l, 0);
                l++;
            }
        }
        
        
        return generateAns(pq);
    }
};