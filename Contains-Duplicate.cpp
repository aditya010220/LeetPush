1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_set<int>s;
5        for(int i=0;i<nums.size();i++){
6           if(!s.contains(nums[i])){
7          s.insert(nums[i]);
8        }
9        else{
10            return true;
11        }
12    }
13    return false;
14    }
15};