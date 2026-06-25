1class Solution {
2public:
3    long long countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5        long long ans = 0;
6
7        for (int l = 0; l < n; l++) {
8            int targetCount = 0;
9
10            for (int r = l; r < n; r++) {
11                if (nums[r] == target) {
12                    targetCount++;
13                }
14
15                int len = r - l + 1;
16
17                if (targetCount > len / 2) {
18                    ans++;
19                }
20            }
21        }
22
23        return ans;
24    }
25};