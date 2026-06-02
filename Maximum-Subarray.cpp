1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int maxSum = INT_MIN;
5        int currentSum = 0;
6        
7        for (int i = 0; i < nums.size(); i++) {
8            currentSum += nums[i];
9            
10            if (currentSum > maxSum) {
11                maxSum = currentSum;
12            }
13            
14            if (currentSum < 0) {
15                currentSum = 0;
16            }
17        }
18        
19        return maxSum;
20    }
21};