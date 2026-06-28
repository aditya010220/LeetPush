1class Solution {
2public:
3vector<vector<int>>res;
4void solve(int idx , vector<int>&nums){
5    if(idx>=nums.size()){
6        res.push_back(nums);
7        return;
8    }
9    for(int i =idx;i<nums.size();i++){
10        swap(nums[i],nums[idx]);
11        solve(idx+1,nums);
12        swap(nums[i],nums[idx]);
13    }
14}
15    vector<vector<int>> permute(vector<int>& nums) {
16        solve(0,nums);
17        return res;
18    }
19};