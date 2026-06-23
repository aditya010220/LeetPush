1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> prefix(n);
7
8        prefix[0] = nums[0];
9
10        for (int i = 1; i < n; i++) {
11            prefix[i] = prefix[i - 1] + nums[i];
12        }
13
14        int totalSum = prefix[n - 1];
15
16        for (int i = 0; i < n; i++) {
17
18            int left = (i == 0) ? 0 : prefix[i - 1];
19
20            int right = totalSum - prefix[i];
21
22            if (left == right) {
23                return i;
24            }
25        }
26
27        return -1;
28    }
29};