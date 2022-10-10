// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        // there is no way to replace a single character to make "a" not a palindrome
        // because no matter what we change, it is still a palindrome
        if (n == 1) return "";
        
        // let's think about n = 2 case, e.g. "bb"
        // in this case, to acheive the lexicographically smallest one
        // we should replace from the left and the best character to use is "a"
        // for "bb", we replace the first "b" to "a" to become "ab"
        
        // let's think about another n = 2 case, e.g. "aa"
        // in this case, to acheive the lexicographically smallest one
        // we should replace from the left and the best character to use is "a"
        // however, for "aa", we cannot use "a" here and the best character to use is "b" now
        // for "aa", we replace the second "a" to "b" to become "ab"
        // why not replace the first "a"? because "ba" is not smallest.
        
        // since the input is a palindrome, we just need to check the first half only
        for (int i = 0; i < n / 2; i++) {
            //  here we know that as long as palindrome[i] is not "a", we skip it
            if (palindrome[i] != 'a') {
                // otherwise, we replace the first character that is not "a"
                palindrome[i] = 'a';
                // replaced -> we can return the result here
                return palindrome;
            }
        }
        // by the time it reaches here, the possible cases would be like "aaa", "aba" etc. 
        // so that we haven't changed anything in above logic
        // in this case, as mentioned above, the best character to use is "b"
        // and we should replace the last character to achieve the smallest one possible
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};