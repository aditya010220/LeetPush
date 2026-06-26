1class Solution {
2public:
3    long long countMajoritySubarrays(vector<int>& nums, int target) {
4        int size = nums.size(), pref = size;
5
6        vector<int> freq(2 * size + 1);
7        freq[size] = 1;
8
9        long long less = 0, ans = 0;
10
11        for (int num : nums) {
12            if (num == target)
13                less += freq[pref++];
14            else
15                less -= freq[--pref];
16
17            ++freq[pref];
18            ans += less;
19        }
20
21        return ans;
22    }
23};