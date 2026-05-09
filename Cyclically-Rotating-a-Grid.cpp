1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4        int T = 0, L = 0;
5        int B = grid.size() - 1, R = grid[0].size() - 1;
6
7        while (T < B && L < R) {
8            int len = B - T, wid = R - L;
9            int perimeter = 2 * len + 2 * wid;
10            int r = k % perimeter;
11
12            while (r--) {
13                int tmp = grid[T][L];
14
15                for (int i = L; i < R; i++)
16                    grid[T][i] = grid[T][i + 1];
17
18                for (int i = T; i < B; i++)
19                    grid[i][R] = grid[i + 1][R];
20
21                for (int i = R; i > L; i--)
22                    grid[B][i] = grid[B][i - 1];
23
24                for (int i = B; i > T; i--)
25                    grid[i][L] = grid[i - 1][L];
26
27                grid[T + 1][L] = tmp;
28            }
29
30            T++; L++;
31            B--; R--;
32        }
33
34        return grid;
35    }
36};