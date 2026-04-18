1class Solution {
2public:
3    int mirrorDistance(int n) {
4        string s = to_string(n);
5        reverse(s.begin(),s.end());
6        int rev = stoi(s);
7        int c = abs(n-rev);
8        return c;
9    }
10};