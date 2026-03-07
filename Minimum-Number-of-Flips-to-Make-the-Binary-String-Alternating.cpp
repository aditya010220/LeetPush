1class Solution {
2public:
3    int minFlips(auto& s) {
4        int n = s.length();
5        int op[2] = {0, 0};
6
7        for (int i = 0; i < n; i++)
8            op[(s[i] ^ i) & 1]++;
9
10        int res = min(op[0], op[1]);
11
12        for (int i = 0; i < n - 1; i++) {
13            op[(s[i] ^ i) & 1]--;
14            op[(s[i] ^ (n + i)) & 1]++;
15            res = min(res, min(op[0], op[1]));
16        }
17
18        return res;
19    }
20};