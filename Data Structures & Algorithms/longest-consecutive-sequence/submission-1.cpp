class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> vis;
        unordered_map<int, int> ans;
        unordered_map<int, int> present;

        for(int i = 0; i < n; i ++) {
            present[nums[i]] = 1;
        }
        int mx = 0;
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            int cnt = 1;
            if (vis[num + 1] == 1) {
                ans[num] = ans[num + 1] + 1;
            } else {
                while(present[num++]){
                    cnt++;
                }
                ans[nums[i]] = cnt;
            }

            
            mx = max(mx, ans[nums[i]]);
            vis[num] = 1;

        }
        return mx == 0 ? 0 : mx - 1;

    }
};
