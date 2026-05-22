1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int left = 0;
5        int right = nums.size() - 1;
6
7        while (left <= right) {
8            int mid = (left + right) / 2;
9
10            if (nums[mid] == target) {
11                return mid;
12            } 
13            // low to mid sorted
14            else if (nums[mid] >= nums[left]) {
15                if (nums[left] <= target && target <= nums[mid]) {
16                    right = mid - 1;
17                } else {
18                    left = mid + 1;
19                }
20            } 
21            // mid to right sorted 
22            else {
23                if (nums[mid] <= target && target <= nums[right]) {
24                    left = mid + 1;
25                } else {
26                    right = mid - 1;
27                }
28            }
29        }
30
31        return -1;        
32    }
33};