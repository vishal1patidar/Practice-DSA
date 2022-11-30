class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int,int> mp;                // map for storing each value occurance
        
        for(auto it : arr)
        {
            mp[it]++;                   // storing the occurance
        }
        
        set<int> st;
        
        for(auto it :  mp)
        {
            // if occurance for any value is already present in the set then return false (not unique)
            if(st.count(it.second)) return false;
            
            st.insert(it.second);                    // puting into the set (occurance)
        }
        
        return true;                                 // return true at the last when there is no duplicate occurance
    }
};

// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) 
//     {
//         sort(arr.begin(),arr.end());                    // sort the array for cheking same elements
//         int cnt = 1;                                    // for counting the occurance of any element
//         set<int> st;                                    // for storing the occurances
        
//         // if arr size is 2 and they are not same , it means they are having same occurance so return return false
//         if(arr.size()==2)
//         {
//             return (arr[0]==arr[1]);
//         }
        
//         // start iterating over the arr
//         for(int i=1;i<arr.size();i++)
//         {
//             // if current and prev values are not same then check the occurance of current cnt in the set , if it is already present in the set then return false 
//             if(arr[i-1] != arr[i])
//             {
//                 if(st.count(cnt) != 0)
//                 {
//                     return false;
//                 }
//                 else
//                 {
//                     st.insert(cnt);                         // if cnt is not in teh set then put it into the set and make cnt 1 again for current value
//                     cnt = 1;
//                 }  
//             }
//             else
//             {
//                 cnt++;                                      // when curr and prev values are same so increase the count
//             }
//         }
//         return true;
//     }
// };