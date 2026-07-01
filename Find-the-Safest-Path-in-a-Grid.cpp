1class Solution {
2public:
3    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
4
5    bool canReach(vector<vector<int>>& dist, int limit) {
6
7        int n = dist.size();
8
9        if (dist[0][0] < limit)
10            return false;
11
12        queue<pair<int,int>> q;
13        vector<vector<bool>> vis(n, vector<bool>(n, false));
14
15        q.push({0,0});
16        vis[0][0] = true;
17
18        while (!q.empty()) {
19
20            auto [r, c] = q.front();
21            q.pop();
22
23            if (r == n - 1 && c == n - 1)
24                return true;
25
26            for (auto &d : dirs) {
27
28                int nr = r + d[0];
29                int nc = c + d[1];
30
31                if (nr >= 0 && nr < n &&
32                    nc >= 0 && nc < n &&
33                    !vis[nr][nc] &&
34                    dist[nr][nc] >= limit) {
35
36                    vis[nr][nc] = true;
37                    q.push({nr, nc});
38                }
39            }
40        }
41
42        return false;
43    }
44
45    int maximumSafenessFactor(vector<vector<int>>& grid) {
46
47        int n = grid.size();
48
49        queue<pair<int,int>> q;
50
51        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
52
53        // Multi-Source BFS
54        for (int i = 0; i < n; i++) {
55            for (int j = 0; j < n; j++) {
56
57                if (grid[i][j] == 1) {
58                    dist[i][j] = 0;
59                    q.push({i, j});
60                }
61            }
62        }
63
64        while (!q.empty()) {
65
66            auto [r, c] = q.front();
67            q.pop();
68
69            for (auto &d : dirs) {
70
71                int nr = r + d[0];
72                int nc = c + d[1];
73
74                if (nr >= 0 && nr < n &&
75                    nc >= 0 && nc < n &&
76                    dist[nr][nc] == INT_MAX) {
77
78                    dist[nr][nc] = dist[r][c] + 1;
79                    q.push({nr, nc});
80                }
81            }
82        }
83
84        int low = 0;
85        int high = 2 * n;
86        int ans = 0;
87
88        while (low <= high) {
89
90            int mid = low + (high - low) / 2;
91
92            if (canReach(dist, mid)) {
93                ans = mid;
94                low = mid + 1;
95            }
96            else {
97                high = mid - 1;
98            }
99        }
100
101        return ans;
102    }
103};