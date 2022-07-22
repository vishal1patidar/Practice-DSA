class Solution {
public:
    int myAtoi(string s) {
        int sign = 1; 
        int result = 0; 
        int index = 0;
        int n = s.size();
        
        // Discard all spaces from the beginning of the input string.
        while (index < n && s[index] == ' ') { 
            index++; 
        }
        
        // sign = +1, if it's positive number, otherwise sign = -1. 
        if (index < n && s[index] == '+') {
            sign = 1;
            index++;
        } else if (index < n && s[index] == '-') {
            sign = -1;
            index++;
        }
        
        // Traverse next digits of input and stop if it is not a digit. 
        // End of string is also non-digit character.
        while (index < n && isdigit(s[index])) {
            int digit = s[index] - '0';

            // Check overflow and underflow conditions. 
            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            // Append current digit to the result.
            result = 10 * result + digit;
            index++;
        }
        
        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign * result; 
    }
};