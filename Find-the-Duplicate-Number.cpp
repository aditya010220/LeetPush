1class Solution {
2public:
3    int findDuplicate(std::vector<int>& nums) {
4        int left = 1;
5        int right = nums.size() - 1;
6
7        while (left < right) {
8            int mid = left + (right - left) / 2;
9            int count = 0;
10
11            // Count the numbers less than or equal to mid
12            for (int num : nums) {
13                if (num <= mid) {
14                    count++;
15                }
16            }
17
18            // If count is greater than mid, the duplicate lies in the left half
19            if (count > mid) {
20                right = mid;
21            } else { // Otherwise, it lies in the right half
22                left = mid + 1;
23            }
24        }
25
26        return left;
27    }
28};