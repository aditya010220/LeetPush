1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(),nums.end());
6        for(int i =0;i<n;i++){
7            if(i!=nums[i]){
8                return i;
9            }
10        }
11        return n;
12    }
13};