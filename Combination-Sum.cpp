1class Solution {
2public:
3vector<vector<int>>result;
4void solve(vector<int>&candidates , int index , int sum , vector<int>&temp , int target){
5    if(index>=candidates.size() || sum>target){
6        return;
7    }
8    if(sum==target){
9        result.push_back(temp);
10        return;
11    }
12    temp.push_back(candidates[index]);
13    solve(candidates , index, sum + candidates[index] , temp , target);
14    temp.pop_back();
15    solve(candidates , index+1, sum, temp , target);
16}
17    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
18        vector<int>temp;
19        solve(candidates,0,0,temp,target);
20        return result;
21    }
22};