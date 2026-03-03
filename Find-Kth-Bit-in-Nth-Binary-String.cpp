1class Solution {
2public:
3    char findKthBit(int n, int k) {
4        if (n == 1) return '0';
5        
6        int len = (1 << n) - 1;
7        int mid = (len + 1) / 2;
8        
9        if (k == mid) return '1';
10        if (k < mid) return findKthBit(n - 1, k);
11        
12        char c = findKthBit(n - 1, len - k + 1);
13        return c == '0' ? '1' : '0';
14    }
15};