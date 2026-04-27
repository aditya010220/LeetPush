1class Solution {
2    static constexpr int TRANS[6][4] = {{-1, 1, -1, 3},
3                                        {0, -1, 2, -1},
4                                        {3, 2, -1, -1},
5                                        {1, -1, -1, 2},
6                                        {-1, 0, 3, -1},
7                                        {-1, -1, 1, 0}};
8    static constexpr int DIRS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
9    static constexpr int START[6][2] = {{1, 3}, {0, 2}, {2, 3},
10                                        {1, 2}, {0, 3}, {0, 1}};
11
12public:
13    bool hasValidPath(vector<vector<int>>& grid) {
14        if (grid[0][0] == 5) return false;
15        if (grid.back().back() == 4) return false;
16
17        int m = grid.size(), n = grid[0].size();
18        if (m == 1 && n == 1) return true;
19
20        auto check = [&](int di) -> bool {
21            if (di == -1) return false;
22            int r = DIRS[di][0];
23            int c = DIRS[di][1];
24            bitset<90000> visit;
25
26            while (r >= 0 && r < m && c >= 0 && c < n) {
27                int cell = r * n + c;
28                if (visit[cell]) return false;
29                visit[cell] = 1;
30
31                di = TRANS[grid[r][c] - 1][di];
32                if (di == -1) return false;
33                if (r == m - 1 && c == n - 1) return true;
34
35                r += DIRS[di][0];
36                c += DIRS[di][1];
37            }
38
39            return false;
40        };
41
42        const int* s = START[grid[0][0] - 1];
43        return check(s[0]) || check(s[1]);
44    }
45};