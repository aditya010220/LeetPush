1class Solution {
2    vector<int> calc_z(const string& s) {
3        int n = s.size();
4        vector<int> z(n);
5        int box_l = 0, box_r = 0; // Left and right boundaries of the z-box (inclusive)
6        for (int i = 1; i < n; i++) {
7            if (i <= box_r) {
8                z[i] = min(z[i - box_l], box_r - i + 1);
9            }
10            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
11                box_l = i;
12                box_r = i + z[i];
13                z[i]++;
14            }
15        }
16        z[0] = n;
17        return z;
18    }
19
20public:
21    string generateString(string s, string t) {
22        int n = s.size(), m = t.size();
23        string ans(n + m - 1, '?');
24
25        // Process T
26        vector<int> z = calc_z(t);
27        int pre = -m;
28        for (int i = 0; i < n; i++) {
29            if (s[i] != 'T') {
30                continue;
31            }
32            int size = max(pre + m - i, 0);
33            // The prefix and suffix of t with length size must be equal
34            if (size > 0 && z[m - size] < size) {
35                return "";
36            }
37            // Positions after size are all '?', so fill in t
38            for (int j = size; j < m; j++) {
39                ans[i + j] = t[j];
40            }
41            pre = i;
42        }
43
44        // Compute the nearest undecided position <= i
45        vector<int> pre_q(ans.size());
46        pre = -1;
47        for (int i = 0; i < ans.size(); i++) {
48            if (ans[i] == '?') {
49                ans[i] = 'a'; // Initial value for undecided positions is a
50                pre = i;
51            }
52            pre_q[i] = pre;
53        }
54
55        // Find positions in ans equal to t, using KMP or the Z-function
56        z = calc_z(t + ans);
57
58        // Process F
59        for (int i = 0; i < n; i++) {
60            if (s[i] != 'F') {
61                continue;
62            }
63            // The substring must not equal t
64            if (z[m + i] < m) {
65                continue;
66            }
67            // Find the last undecided position
68            int j = pre_q[i + m - 1];
69            if (j < i) { // None exists
70                return "";
71            }
72            ans[j] = 'b';
73            i = j; // Jump directly to j
74        }
75
76        return ans;
77    }
78};