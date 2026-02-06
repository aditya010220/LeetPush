1class Solution {
2public:
3    int minRemoval(vector<int>& nums, int k) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        int i = 0;
7        int maxLen = 0;
8        
9        for (int j = 0; j < n; j++) {
10            // Cast to long long to prevent overflow
11            while ((long long)nums[j] > (long long)nums[i] * k) {
12                i++;
13            }
14            maxLen = max(maxLen, j - i + 1);
15        }
16        
17        return n - maxLen;
18    }
19};