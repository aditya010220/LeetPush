1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& nums) {
4        int n = (int)nums.size();
5        vector<int> result(n);
6        for(int i = 0; i < n; i ++){
7            result[i] = nums[((i + nums[i]) % n + n) % n];
8        }
9        return result;
10    }
11};