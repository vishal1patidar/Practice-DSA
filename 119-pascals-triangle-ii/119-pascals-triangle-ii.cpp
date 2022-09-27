class Solution {
public:
    vector<int> getRow(int rowIndex) {
  vector<int> row(rowIndex + 1);
  row[0] = 1;
  if (!rowIndex) return row;

  for (int r = 1; r <= rowIndex; r++) {
	int x1 = row[0];
	int x2 = row[1];
	for (int i = 1; i < r; i++) {
	  x2 = row[i];
	  row[i] += x1;
	  x1 = x2;
	}
	row[r] = 1;
  }
  return row;
}
};