1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        int n = grid.size(), m = grid[0].size();
5        int N = n * m;
6        int freq[10001] = {0};
7        int mn = grid[0][0], mx = mn;
8
9        for (const auto& row : grid) {
10            for (int val : row) {
11                if ((val - grid[0][0]) % x != 0) return -1;
12                freq[val]++;
13                mn = min(mn, val);
14                mx = max(mx, val);
15            }
16        }
17
18        int target = (N + 1) / 2;
19        int acc = 0, median = mn;
20
21        for (int i = mn; i <= mx; i += x) {
22            acc += freq[i];
23            if (acc >= target) {
24                median = i;
25                break;
26            }
27        }
28
29        int ops = 0;
30        for (int i = mn; i <= mx; i += x)
31            ops += abs(i - median) / x * freq[i];
32
33        return ops;
34    }
35};