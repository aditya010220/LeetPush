1class Solution {
2public:
3    int func(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
4        
5        if (j - i <= 1) return 0;
6
7        if (dp[i][j] != -1) return dp[i][j];
8
9        int mini = INT_MAX;
10        for (int k = i + 1; k < j; k++) {
11            int cost = (cuts[j] - cuts[i]) 
12                     + func(i, k, cuts, dp) 
13                     + func(k, j, cuts, dp);
14
15            mini = min(mini, cost);
16        }
17
18        return dp[i][j] = mini;
19    }
20
21    int minCost(int n, vector<int>& cuts) {
22        cuts.push_back(0);
23        cuts.push_back(n);
24        sort(cuts.begin(), cuts.end());
25
26        int m = cuts.size();
27        vector<vector<int>> dp(m, vector<int>(m, -1));
28
29        return func(0, m - 1, cuts, dp);
30    }
31};