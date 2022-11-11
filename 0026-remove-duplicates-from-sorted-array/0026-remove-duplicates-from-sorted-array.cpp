class Solution {
public:
         int removeDuplicates(vector<int>& arr) {
       set < int > set;
       for (int i = 0; i < arr.size(); i++) {
           set.insert(arr[i]);
      }
      int k = set.size();
      int j = 0;
      for (int x: set) {
          arr[j++] = x;
      }
     return k;
         }
};