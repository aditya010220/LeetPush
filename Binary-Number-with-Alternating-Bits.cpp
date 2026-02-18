1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        while(n>0){
5            if((n&1) == ((n>>1)&1)){
6                return false;
7            }
8            n=n>>1;
9        }
10        return true;
11        
12    }
13};