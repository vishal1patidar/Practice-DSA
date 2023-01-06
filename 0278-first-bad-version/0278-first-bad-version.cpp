// intuition
// This problem is a version of binary search much like findind the first occurrence of element in sorted array containing duplicate elements.
// Approach
// Applying binary search, if a bad version is found we check if the number on the left ( mid-1 ) is also a bad version or not.
// If the number on the left is not a bad version then we can simply return the current number as it is the first bad version.
// If the number on the left is a bad version then we can set r = mid-1 and continue with binary search.
// If current number is not a bad version then we can set l = mid+1.
// Complexity
// Time complexity: O(log n)
// Space complexity: O(1)
// Code
// CPP / C++

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;

        while( l<=r ) {
            int mid = l + (r-l)/2;
            if( isBadVersion(mid) ) {
                if( isBadVersion(mid) != isBadVersion(mid-1) ) return mid;
                else r = mid-1;
            }
            else l = mid+1;
        }
        return -1;
    }
};
