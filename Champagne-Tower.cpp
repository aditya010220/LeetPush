1class Solution {
2public:
3    double champagneTower(int poured, int query_row, int query_glass) {
4        double tower[102][102] = {0.0};
5        tower[0][0] = (double)poured;
6        
7        for (int r = 0; r <= query_row; r++) {
8            for (int c = 0; c <= r; c++) {
9                if (tower[r][c] > 1.0) {
10                    double excess = (tower[r][c] - 1.0) / 2.0;
11                    tower[r][c] = 1.0;
12                    tower[r + 1][c] += excess;
13                    tower[r + 1][c + 1] += excess;
14                }
15            }
16        }
17        return tower[query_row][query_glass];
18    }
19};