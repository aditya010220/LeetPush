1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int x=0, r=0;
5        for(char c: moves){
6            x+=(c=='R')-(c=='L');
7            r+=c=='_';
8        }
9        return abs(x)+r;
10    }
11};