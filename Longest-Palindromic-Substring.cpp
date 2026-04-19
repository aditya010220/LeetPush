1class Solution {
2public:
3    string longestPalindrome(string s) {
4        int n = s.length();
5        if (n <= 1) return s;
6
7        int start = 0, maxLen = 1;
8
9        for (int i = 0; i < n; i++) {
10            expand(s, i, i, start, maxLen);     
11            expand(s, i, i + 1, start, maxLen); 
12        }
13
14        return s.substr(start, maxLen);
15    }
16
17private:
18    void expand(string &s, int left, int right, int &start, int &maxLen) {
19        while (left >= 0 && right < s.length() && s[left] == s[right]) {
20            if (right - left + 1 > maxLen) {
21                start = left;
22                maxLen = right - left + 1;
23            }
24            left--;
25            right++;
26        }
27    }
28};