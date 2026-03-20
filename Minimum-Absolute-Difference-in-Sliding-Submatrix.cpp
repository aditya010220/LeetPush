1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
4        int n = grid.size(), m = grid[0].size();
5        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
6        for (int i = 0; i <= n - k; i++) {
7            map<int, int> mp;
8            for (int r = i; r < i + k; r++) {
9                for (int c = 0; c < k; c++) {
10                    mp[grid[r][c]]++;
11                }
12            }
13            for (int c = 0; c <= m - k; c++) {
14                if (mp.size() > 1) {
15                    int mini = 1e9;
16                    auto it = mp.begin();
17                    int prev = it->first;
18                    for (++it; it != mp.end(); it++) {
19                        mini = min(mini, abs(it->first - prev));
20                        prev = it->first;
21                    }
22                    ans[i][c] = mini;
23                } else {
24                    ans[i][c] = 0;
25                }
26
27                if (c < m - k) {
28                    for (int r = i; r < i + k; r++) {
29                        mp[grid[r][c]]--;
30                        if (mp[grid[r][c]] == 0)
31                            mp.erase(grid[r][c]);
32                        mp[grid[r][c + k]]++;
33                    }
34                }
35            }
36        }
37        return ans;
38    }
39};