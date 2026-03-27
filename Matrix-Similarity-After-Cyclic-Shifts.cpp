1class Solution {
2public:
3    bool areSimilar(vector<vector<int>>& mat, int k) {
4        int m = mat.size();
5        int n = mat[0].size();
6
7        k %= n;  //(reduce k<n)
8
9        for (int i = 0; i < m; i++) {
10            for (int j = 0; j < n; j++) {
11                if (i % 2 == 0) {
12                    // even row , left rotate
13                    if (mat[i][j] != mat[i][(j + k) % n])
14                        return false;
15                } else {
16                    // odd row , right rotate
17                    if (mat[i][j] != mat[i][(j - k + n) % n])
18                        return false;
19                }
20            }
21        }
22
23        return true;
24    }
25};