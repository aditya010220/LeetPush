1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int lower = 0;
5        int upper = 0;
6
7        for(char ch : word) {
8            if(islower(ch)) {
9                lower |= (1 << (ch - 'a'));
10            } 
11            else if(isupper(ch)) {
12                upper |= (1 << (ch - 'A'));
13            }
14        }
15
16        int common = lower & upper;
17
18        return __builtin_popcount(common);
19    }
20};