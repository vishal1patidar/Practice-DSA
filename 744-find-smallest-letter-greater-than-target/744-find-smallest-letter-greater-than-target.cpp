class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto x:letters){
            if(x-'a'>target-'a')
                return x;
        }
        return letters[0];
    }
};