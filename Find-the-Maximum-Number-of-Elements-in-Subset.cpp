1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<long long, int> freq;
5
6        for (auto& n : nums) freq[n]++;
7
8        int res = (freq[1] - 1) | 1;
9        freq.erase(1);
10
11        for (auto& f : freq) {
12            long long x = f.first;
13            long long sq = sqrt(x);
14
15            if (sq * sq == x && freq.count(sq) && freq[sq] > 1) continue;
16
17            int n = 0;
18
19            while (freq.count(x) && freq[x] > 1) {
20                n += 2;
21                x *= x;
22            }
23
24            res = fmax(res, n + ((freq.count(x) << 1) - 1));
25        }
26
27        return res;
28    }
29};