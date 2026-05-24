1class Solution {
2public:
3    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
4        if (dp[i] != -1)
5            return dp[i];
6
7        int best = 1;
8        int n = arr.size();
9
10        for (int nxt = i + 1; nxt <= min(n - 1, i + d); nxt++) {
11            if (arr[nxt] >= arr[i])
12                break;
13
14            best = max(best, 1 + dfs(nxt, arr, d, dp));
15        }
16
17        for (int nxt = i - 1; nxt >= max(0, i - d); nxt--) {
18            if (arr[nxt] >= arr[i])
19                break;
20
21            best = max(best, 1 + dfs(nxt, arr, d, dp));
22        }
23
24        return dp[i] = best;
25    }
26
27    int maxJumps(vector<int>& arr, int d) {
28        int n = arr.size();
29        vector<int> dp(n, -1);
30
31        int ans = 1;
32
33        for (int i = 0; i < n; i++) {
34            ans = max(ans, dfs(i, arr, d, dp));
35        }
36
37        return ans;
38    }
39};