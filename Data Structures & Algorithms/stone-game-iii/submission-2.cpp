class Solution {
public:

    int getAns(int i, int turn, vector<int>&stoneValue, vector<vector<int>>&dp) {
        int n = stoneValue.size();
        if (i >= n){
             return 0;
        }
        if (dp[i][turn] != -1) {
            return dp[i][turn];
        }
        int res = -1e9;
        if (turn == 0) {
            res = max(res, stoneValue[i] + getAns(i + 1, abs(turn - 1), stoneValue, dp));
            if(i + 1 < n) {
                res = max(res, stoneValue[i] + stoneValue[i + 1] + getAns(i + 2, abs(turn - 1), stoneValue, dp));
            }
            if(i + 2 < n)
                res = max(res, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + getAns(i + 3, abs(turn - 1), stoneValue, dp));
        } else {
            int x = getAns(i + 1, abs(turn - 1), stoneValue, dp);
            int y = getAns(i + 2, abs(turn - 1), stoneValue, dp);
            int z = getAns(i + 3, abs(turn - 1), stoneValue, dp);
            res = min(x, min(y, z));
        }
        
        return dp[i][turn] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int x = getAns(0, 0, stoneValue, dp);
        int total = 0;
        for(int i = 0; i < n; i ++) {
            total += stoneValue[i];
        }
        cout << x << endl;
        if(total % 2 == 0) {
            if (x == total / 2) {
                return "Tie";
            } else{
                if (x > total/2) {
                    return "Alice";
                }
                else {
                    return "Bob";
                }
            }
        } else{
            if (x > total/2) {
                return "Alice";
            } else {
                return "Bob";
            }
        }

    }
};