1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        unordered_set<string> st;
5
6        for (int i = 0; i + k <= s.size(); i++) {
7            st.insert(s.substr(i, k));
8        }
9
10        return st.size() == (int)pow(2, k);
11    }
12};