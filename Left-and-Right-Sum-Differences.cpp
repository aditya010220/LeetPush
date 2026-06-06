1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int right_sum=0;
5
6        for(int i=0;i<nums.size();i++){
7            right_sum+=nums[i];
8        }
9
10        int left_sum=0;
11        vector<int> result;
12        for(int i=0;i<nums.size();i++){
13            right_sum -= nums[i];
14            result.push_back(abs(left_sum-right_sum));
15            left_sum += nums[i];
16        }
17
18        return result;
19    }
20};