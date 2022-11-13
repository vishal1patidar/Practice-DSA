class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &rows, unordered_map<int, vector<int>> &cols, unordered_set<int> &v_rows, int row) {
  auto res = 0;
  if (v_rows.insert(row).second) {
    res += rows[row].size();
    for (auto c : rows[row])
      for (auto r : cols[c]) res += dfs(rows, cols, v_rows, r);
  }
  return res;
}
int removeStones(vector<vector<int>>& stones) {
  unordered_map<int, vector<int>> rows, cols;
  unordered_set<int> v_rows;
  auto res = 0;
  for (auto s : stones) rows[s[0]].push_back(s[1]), cols[s[1]].push_back(s[0]);
  for (auto r : rows) res += max(0, dfs(rows, cols, v_rows, r.first) - 1);
  return res;
}
};