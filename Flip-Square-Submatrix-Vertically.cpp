1class Solution {
2public:
3    vector<vector<int>>& reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
4        for (int i = 0; i < k; i++)
5            for (int j = 0; j < k >> 1; j++)
6                swap(grid[x + j][y + i], grid[x + k - j - 1][y + i]);
7
8        return grid;
9    }
10};