1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6        int MARK = 1000000;
7
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (matrix[i][j] == 0) {
11
12                    for (int col = 0; col < m; col++) {
13                        if (matrix[i][col] != 0)
14                            matrix[i][col] = MARK;
15                    }
16
17                    for (int row = 0; row < n; row++) {
18                        if (matrix[row][j] != 0)
19                            matrix[row][j] = MARK;
20                    }
21                }
22            }
23        }
24
25        for (int i = 0; i < n; i++) {
26            for (int j = 0; j < m; j++) {
27                if (matrix[i][j] == MARK)
28                    matrix[i][j] = 0;
29            }
30        }
31    }
32};