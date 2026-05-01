1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5        
6        long sum = 0;
7        long F = 0;
8        
9        for(int i = 0; i < n; i++) {
10            sum += nums[i];
11            F += (long)i * nums[i];
12        }
13        
14        long result = F;
15        
16        for(int k = 1; k < n; k++) {
17            F = F + sum - (long)n * nums[n - k];
18            
19            result = max(result, F);
20        }
21        
22        return (int)result;
23    }
24};