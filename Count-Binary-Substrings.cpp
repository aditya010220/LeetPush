1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        int res = 0, prev = 0, strk = 1;
5
6        for (int i = 1; i < s.size(); i++) {
7            if (s[i] == s[i - 1]) strk++;
8            else {
9                prev = strk;
10                strk = 1;
11            }
12            if (strk <= prev) res++;
13        }
14        return res;
15    }
16};
17