1class Solution {
2public:
3    bool canReach(string s, int minJ, int maxJ) {
4        int n = s.length();
5
6        if (s.back() & 1) return false;
7
8        s[0] = 'v';
9        int reach = 0, maxR = maxJ;
10
11        for (int i = minJ; i < n; i++) {
12            if (i > maxR) return false;
13
14            reach += s[i - minJ] == 'v';
15            reach -= (i > maxJ) && s[i - maxJ - 1] == 'v';
16
17            if (reach && (~s[i] & 1)) {
18                s[i] = 'v';
19                maxR = i + maxJ;
20            }
21        }
22
23        return reach;
24    }
25};