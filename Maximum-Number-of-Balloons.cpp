1class Solution {
2public:
3    int maxNumberOfBalloons(string t) {
4        int f[5] = {0};
5        string s = "balon";
6
7        for (uint32_t ch : t)
8            for (int i = 0; i < 5; i++)
9                f[i] += !(ch ^ s[i]);
10
11        return min({f[0], f[1], f[2] >> 1, f[3] >> 1, f[4]});
12    }
13};