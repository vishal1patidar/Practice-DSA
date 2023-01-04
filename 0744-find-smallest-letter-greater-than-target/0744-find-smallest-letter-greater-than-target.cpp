class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0, n = letters.size(), end = n-1;
        while(start<=end)
        {
           int mid=start+(end-start)/2;
            if(target<letters[mid])
            {end=mid-1;
            }
            else
            {
                start=mid+1;  
            }
        }
        return letters[start%n];
    }
};