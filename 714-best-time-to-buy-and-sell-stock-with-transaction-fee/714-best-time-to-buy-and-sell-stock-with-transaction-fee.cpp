class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
		int n=prices.size();
		function<int(int,int)> recur=[&](int i,int hold){
			if(i>=n) return 0;
			if(dp[i][hold]!=-1) return dp[i][hold];
			int res=0;
			if(!hold) {
				res=max(recur(i+1,!hold)-prices[i],
					   recur(i+1,hold));
			}
			else {
				res=max(recur(i+1,!hold)+prices[i]-fee,
					   recur(i+1,hold));
			}
			return dp[i][hold]=res;
		};
		return recur(0,0);
	}
};
