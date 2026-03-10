1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        const int MOD = 1e9 + 7;
5        vector<vector<array<long,2>>> dp(
6            zero+1, vector<array<long,2>>(one+1, {0LL,0LL}));
7
8        for (int i = 1; i <= min(zero,limit); i++) dp[i][0][0] = 1;
9        for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;
10
11        for (int i = 1; i <= zero; i++) {
12            for (int j = 1; j <= one; j++) {
13                long over0 = (i-limit >= 1) ? dp[i-limit-1][j][1] : 0;
14                long over1 = (j-limit >= 1) ? dp[i][j-limit-1][0] : 0;
15                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] - over0 + MOD) % MOD;
16                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1] - over1 + MOD) % MOD;
17            }
18        }
19        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
20    }
21};