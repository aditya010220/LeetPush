1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        unordered_map<int,int>mp;
5        for(int i =0;i<nums.size();i++){
6            mp[nums[i]]++;
7        }
8        for(auto i : mp){
9            if(i.second==1){
10                return i.first;
11            }
12        }
13        return 0;
14    }
15};