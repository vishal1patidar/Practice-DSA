class Solution {
public:
    int solve(string &a, string &b, int i, int j){
        if(i >= a.size()){
            return (b.size()-j);
        }
        if(j >= b.size()){
            return (a.size()-i);
        }

        int ans;
        if(a[i] == b[j]){
            ans = solve(a, b, i+1, j+1);
        }
        else{
            int ins = 1 + solve(a, b, i, j+1);
            int dlt = 1 + solve(a, b, i+1, j);
            int rep = 1 + solve(a, b, i+1, j+1);

            ans = min(ins, min(dlt, rep));
        }

        return ans;
    }

    int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if(i >= a.size()){
            return (b.size()-j);
        }
        if(j >= b.size()){
            return (a.size()-i);
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans;
        if(a[i] == b[j]){
            ans = solveMem(a, b, i+1, j+1, dp);
        }
        else{
            int ins = 1 + solveMem(a, b, i, j+1, dp);
            int dlt = 1 + solveMem(a, b, i+1, j, dp);
            int rep = 1 + solveMem(a, b, i+1, j+1, dp);

            ans = min(ins, min(dlt, rep));
        }

        return dp[i][j] = ans;
    }

    int solveTab(string &a, string &b){
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

        for(int j = 0; j <= b.size(); j++){
            dp[a.size()][j] = b.size() - j; 
        }

        for(int i = 0; i <= a.size(); i++){
            dp[i][b.size()] = a.size() - i;
        }

        for(int i = a.size()-1; i >= 0; i--){
            for(int j = b.size()-1; j >= 0; j--){

                int ans;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int ins = 1 + dp[i][j+1];
                    int dlt = 1 + dp[i+1][j];
                    int rep = 1 + dp[i+1][j+1];

                    ans = min(ins, min(dlt, rep));
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int solveSO(string a, string b){

        vector<int> curr(b.size() + 1, 0);
        vector<int> next(b.size() + 1, 0);

        for(int j = 0; j <= b.size(); j++){
            next[j] = b.size() - j;
        }

        for(int i = a.size()-1; i >= 0; i--){

            // Very Imp, This came from base case
            curr[b.size()] = a.size() - i;

            for(int j = b.size()-1; j >= 0; j--){

                int ans;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    int ins = 1 + curr[j+1];
                    int dlt = 1 + next[j];
                    int rep = 1 + next[j+1];

                    ans = min(ins, min(dlt, rep));
                }

                curr[j] = ans;
            }

            next = curr;
        }

        return curr[0];
    }

    int minDistance(string a, string b) {

        // vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
        // return solveMem(a, b, 0, 0);

        if(a.size() == 0) return b.size();
        if(b.size() == 0) return a.size();

        return solveSO(a, b);
    }
};