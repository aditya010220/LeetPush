1class Solution {
2public:
3    static constexpr int MOD = 1000000007;
4    int zigZagArrays(int n, int l, int r) {
5        int m = r - l + 1;
6        vector<int> dp(m, 1);
7
8        for (int i = 2; i <= n; i++) {
9            reverse(dp.begin(), dp.end());
10            int sum = 0;
11            for (auto& d : dp)
12                sum = (sum + exchange(d, sum)) % MOD;
13        }
14
15        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;
16    }
17};