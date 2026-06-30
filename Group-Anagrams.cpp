1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4       unordered_map<string, vector<string>> mp;
5       for(string s : strs){
6          string key = s;
7       sort(key.begin(),key.end());
8       mp[key].push_back(s);
9       }
10
11       vector<vector<string>>ans;
12       for(auto i : mp) {
13        ans.push_back(i.second);
14       }
15       return ans;
16    }
17};