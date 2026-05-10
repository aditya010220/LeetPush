1class Solution {
2public:
3    int maximumJumps(vector<int>& nums, int target) {
4        int n = nums.size();
5
6        vector<int> dp(n, -1);
7
8        // base case
9        dp[0] = 0;
10
11        for(int i = 0; i < n; i++) {
12
13            // unreachable index
14            if(dp[i] == -1) continue;
15
16            for(int j = i + 1; j < n; j++) {
17                long long diff = 1LL * nums[j] - nums[i];
18
19                if(-target <= diff && diff <= target) {
20                    dp[j] = max(dp[j], dp[i] + 1);
21                }
22            }
23        }
24
25        return dp[n - 1];
26    }
27};