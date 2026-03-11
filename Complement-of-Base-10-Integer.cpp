1class Solution {
2public:
3    int bitwiseComplement(int n) {
4    int mask = n | 1; // edge case n == 0
5    for (int i = 0; i <= 4; i++)
6        mask |= mask >> (1 << i);
7    return n ^ mask; // alternative
8}
9};