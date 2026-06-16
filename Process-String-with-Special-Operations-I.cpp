1//translated using AI
2class Solution {
3public:
4    string processStr(string s) {
5        string res;
6        int n = s.length();
7
8        for (int i = 0; i < n; i++) {
9            char ch = s[i];
10
11            if (ch == '*') {
12                if (res.length() != 0) {
13                    res.pop_back();
14                }
15            } 
16            else if (ch == '#') {
17                res += res;
18            } 
19            else if (ch == '%') {
20                reverse(res.begin(), res.end());
21            } 
22            else if (ch >= 'a' && ch <= 'z') {
23                res.push_back(ch);
24            }
25        }
26
27        return res;
28    }
29};