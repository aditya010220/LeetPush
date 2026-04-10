1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size();
5        int last2[100] = {};
6        int res = 200;
7
8        for (int i = 0; i < n; i++) {
9            int val = nums[i] - 1, pos = i + 1;
10            int pack = last2[val];
11            int old = pack & 255, cur = pack >> 8;
12
13            last2[val] = cur | (pos << 8);
14
15            if (old) res = min(res, (pos - old) << 1);
16        }
17
18        return -(res == 200) | res;
19    }
20};