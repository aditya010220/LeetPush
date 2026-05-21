1class Solution {
2public:
3    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
4
5        unordered_set<string> st;
6
7        // store all prefixes from arr1
8        for (int x : arr1) {
9
10            string s = to_string(x);
11            string pref = "";
12
13            for (char c : s) {
14                pref += c;
15                st.insert(pref);
16            }
17        }
18
19        int ans = 0;
20
21        // check prefixes of arr2
22        for (int y : arr2) {
23
24            string s = to_string(y);
25            string pref = "";
26
27            for (char c : s) {
28
29                pref += c;
30
31                if (st.count(pref))
32                    ans = max(ans, (int)pref.size());
33            }
34        }
35
36        return ans;
37    }
38};