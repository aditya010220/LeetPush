1class Solution {
2public:
3    int minMirrorPairDistance(vector<int>& nums) {
4        int res = 100000, i = 0;
5        unordered_map<int, int> seen;
6
7        for (int& n : nums) {
8            int r;
9            if (seen.count(n))
10                res = min(res, i - seen[n]);
11
12            for (r = 0; n; n /= 10)
13                r = r * 10 + (n % 10);
14
15            seen[r] = i++;
16        }
17
18        return -(res == 100000) | res;
19    }
20};