class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (auto &c: t) (sum+=c)%=256;
        for (auto &c: s) (sum-=c)%=256;
        return (char)sum;
    }
};