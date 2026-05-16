1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int l = 0;
5        int r = nums.size() - 1;
6
7        while(l < r) {
8
9            int mid = l + (r - l) / 2;
10            if(nums[mid] < nums[r]) {
11                r = mid;
12            }
13            else if(nums[mid] > nums[r]) {
14                l = mid + 1;
15            }
16            // duplicates
17            else {
18                r--;
19            }
20        }
21
22        return nums[l];
23    }
24};