1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        return *partition_point(nums.begin(), nums.end(), [&](int n) { return n > nums.back(); });
5    }
6};