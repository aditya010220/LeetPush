1class Solution {
2public:
3    int reverseBits(int n) {
4        int rev = 0;
5        for(int i = 0; i < 32; i++) {
6            rev = (rev << 1) | ((n >> i) & 1);
7        }
8        return rev;
9    }
10};