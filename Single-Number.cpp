1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4         int n = nums.size();
5        //  vector<int>ans(n);
6        int ans=0;
7         for(int i =0;i<n;i++){
8            ans = ans^nums[i];
9         }
10         return ans;
11    }
12};