1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        
7        set<int> st;
8
9        for(int i = 0; i < m; i++) {
10            for(int j = 0; j < n; j++) {
11
12                // size 0 rhombus
13                st.insert(grid[i][j]);
14
15                for(int k = 1; ; k++) {
16
17                    int r = i + 2*k;
18                    int left = j - k;
19                    int right = j + k;
20
21                    if(r >= m || left < 0 || right >= n) break;
22
23                    int sum = 0;
24
25                    int x = i, y = j;
26
27                    // top -> right
28                    for(int t = 0; t < k; t++) {
29                        sum += grid[x + t][y + t];
30                    }
31
32                    // right -> bottom
33                    for(int t = 0; t < k; t++) {
34                        sum += grid[x + k + t][y + k - t];
35                    }
36
37                    // bottom -> left
38                    for(int t = 0; t < k; t++) {
39                        sum += grid[x + 2*k - t][y - t];
40                    }
41
42                    // left -> top
43                    for(int t = 0; t < k; t++) {
44                        sum += grid[x + k - t][y - k + t];
45                    }
46
47                    st.insert(sum);
48                }
49            }
50        }
51
52        vector<int> ans;
53        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it) {
54            ans.push_back(*it);
55        }
56
57        return ans;
58    }
59};