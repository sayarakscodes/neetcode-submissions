class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        if (n == 2){
            return max(nums[1], nums[0]);
        }
       vector<vector<int>> dp(n, vector<int>(2, -1e9)); 
       dp[0][0] = nums[0];
       dp[1][0] = max(nums[1], dp[0][0]);
       dp[n -1][1] = nums[n - 1];
       dp[n - 2][1] = max(nums[n - 2], dp[n-1][1]);

       int ans = max(dp[0][0], max(dp[1][0], max(dp[n-1][1], dp[n-2][1])));
       for(int i = 2; i < n - 1; i ++) {
            dp[i][0] = max(nums[i] + dp[i - 2][0], dp[i - 1][0]);
            ans = max(ans, dp[i][0]);

       }
       for(int i = n - 3; i > 0; i --) {
            dp[i][1] = max(nums[i] + dp[i + 2][1], dp[i + 1][1]);
            ans = max(ans, dp[i][1]);
       }
       return ans;

    }
};
