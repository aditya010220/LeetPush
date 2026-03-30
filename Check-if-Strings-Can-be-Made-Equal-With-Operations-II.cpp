1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        long long eX = 0, oX = 0, eS = 0, oS = 0;
5        
6        for (int i = 0; i < s1.length(); ++i) {
7            int v1 = s1[i], v2 = s2[i];
8            int dx = v1 ^ v2;
9            int ds = (v1 * v1) - (v2 * v2);
10            if (i & 1) {
11                oX ^= dx;
12                oS += ds;
13            } else {
14                eX ^= dx;
15                eS += ds;
16            }
17        }
18        return !(eX | oX | eS | oS);
19    }
20};