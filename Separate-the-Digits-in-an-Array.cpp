1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        
5        vector<int> result;
6
7        for (int num : nums) {
8
9            string s = to_string(num);
10
11            for (char ch : s) {
12
13                result.push_back(ch - '0');
14            }
15        }
16
17        return result;
18    }
19};