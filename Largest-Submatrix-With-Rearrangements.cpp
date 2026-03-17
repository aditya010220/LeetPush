1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& matrix) {
4        auto m = matrix.size(), n = matrix[0].size();
5        int res = 0;
6
7        for (int i = 1; i < m; i++)
8            for (int j = 0; j < n; j++)
9                if (matrix[i][j] == 1)
10                    matrix[i][j] += matrix[i - 1][j];
11
12        for (int i = 0; i < m; i++) {
13            sort(matrix[i].rbegin(), matrix[i].rend());
14            for (int j = 0; j < n; j++)
15                res = max(res, matrix[i][j] * (j + 1));
16        }
17
18        return res;
19    }
20};