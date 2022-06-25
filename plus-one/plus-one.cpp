class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size(), a = 0;
        bool check = false;
        vector<int> ans;
        for (int i = l - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                a = i + 1;
                break;
            }
            if (i == 0 and digits[i] == 9) {
                ans.push_back(1);
                check = true;
                break;
            }
        }
        if (check) {
            for (int i = 0; i < digits.size(); i++) {
                ans.push_back(0);
            }
            return ans;
        }
        else {
            for (int i = a; i < digits.size(); i++) {
                digits[i] = 0;
            }
            return digits;
        }
        return ans;
    }
};