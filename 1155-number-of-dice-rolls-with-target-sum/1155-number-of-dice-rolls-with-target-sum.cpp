/*Basic Solution (TLE)
A basic brute-force solution could be to try all combinations of all faces for all dices, and count the ones that give a total sum of target.

class Solution {
public:
int numRollsToTarget(int d, int f, int target, int res = 0) {
  if (d == 0 || target <= 0) return d == target;
  for (auto i = 1; i <= f; ++i)
    res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
  return res;
}
};


d == target is the shorthand for d == 0 && target == 0.

Complexity Analysis
Runtime: O(f ^ d).
Memory: O(d) for the stack.
*/

/*Top-down DP
We memoise the previously computed results for dice i and and target.

Since dp is initialized with zeros, we store there res + 1 to check if the result has been pre-computed. This is an optimization for brevity and speed.
class Solution {
public:
int dp[31][1001] = {};
int numRollsToTarget(int d, int f, int target, int res = 0) {
  if (d == 0 || target <= 0) return d == target;
  if (dp[d][target]) return dp[d][target] - 1;
  for (auto i = 1; i <= f; ++i)
    res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
  dp[d][target] = res + 1;
  return res;
}
};
Complexity Analysis
Runtime: O(d * f * target).
Memory: O(d * target) for the memoisation.

*/


/*Bottom-Up DP
We can define our dp[i][k] as number of ways we can get k using i dices. As an initial point, there is one way to get to 0 using zero dices.

Then, for each dice i and face j, accumulate the number of ways we can get to k.

Note that for the bottom-up solution, we can reduce our memory complexity as we only need to store counts for the previous dice.

*/
class Solution {
public:
int numRollsToTarget(int d, int f, int target) {
  vector<int> dp(target + 1);
  dp[0] = 1;
  for (int i = 1; i <= d; ++i) {
    vector<int> dp1(target + 1);
    for (int j = 1; j <= f; ++j)
      for (auto k = j; k <= target; ++k)
        dp1[k] = (dp1[k] + dp[k - j]) % 1000000007;
    swap(dp, dp1);
  }
  return dp[target];
}
};
// Complexity Analysis
// Runtime: O(d * f * target).
// Memory: O(target) as we only store counts for the last dice.

