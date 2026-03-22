1class Solution {
2public:
3    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
4        int n = mat.size();
5        int m = 0b1111;
6
7        for (int i = 0; i < n; i++) {
8            for (int j = 0; j < n; j++) {
9                if (mat[i][j] != target[i][j]) m &= 0b1110;
10                if (mat[i][j] != target[j][n - 1 - i]) m &= 0b1101;
11                if (mat[i][j] != target[n - 1 - i][n - 1 - j]) m &= 0b1011;
12                if (mat[i][j] != target[n - 1 - j][i]) m &= 0b0111;
13                if (m == 0) return false;
14            }
15        }
16
17        return m != 0;
18    }
19};
20