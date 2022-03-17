class Solution {
public:
    int scoreOfParentheses(string s) {
         stack<int> stack;
        int cur = 0;
        for (char i : s)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
};

/*cur record the score at the current layer level.

If we meet '(',
we push the current score to stack,
enter the next inner layer level,
and reset cur = 0.

If we meet ')',
the cur score will be doubled and will be at least 1.
We exit the current layer level,
and set cur += stack.pop() + cur

Complexity: O(N) time and O(N) space */



   