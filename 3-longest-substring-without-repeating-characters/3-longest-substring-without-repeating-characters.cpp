/*
   basic idea:
   set a book with 128 capacity to check if the char has appeared.    //book: vector<bool>(128)
   set count, longest, left;    //record where the left boundary now count contained is
   traverse the string s:
        if(s[i] not in the book)    //book[s[i]] == false
            count++
            mark s[i] in the book   //book[s[i]] = true
        else
            update longest      //longest = max(longest, count)
            update left and book:
                left++ until meet the repeat char s[i]
                 update book to remove the char s[left]
            update count = i-left+1
    return longest
   */
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<bool>book(128,false);
            int left, cnt, longest;
            left = 0, cnt = 0, longest = 0;
            for(int i = 0;i < s.size();i++){
                if(book[s[i]] == false){
                    cnt++;
                    book[s[i]] = true;
                }
                else{
                    longest = max(longest, cnt);
                    while(s[left] != s[i]){
                        book[s[left]] = false;
                        left++;
                    }
                    left++;
                    cnt = i-left+1;

                }
            }
            longest = max(longest, cnt);
            return longest;
        }
};