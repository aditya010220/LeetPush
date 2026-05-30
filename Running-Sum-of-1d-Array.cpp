1class Solution {
2public:
3    vector<int> runningSum(vector<int>& nums) {
4        int n = nums.size();
5        for(int i =1;i<n;i++){
6            nums[i] = nums[i]+nums[i-1];
7        }
8        return nums;
9    }
10};