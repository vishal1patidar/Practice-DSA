class Solution {
public:
    
      vector<int> intersect(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
    return a;
}  
};