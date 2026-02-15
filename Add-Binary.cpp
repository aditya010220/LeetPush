1class Solution {
2public:
3    string addBinary(string a, string b) {
4        string res;
5        int carry = 0;
6        int i = a.length() - 1;
7        int j = b.length() - 1;
8
9        while (i >= 0 || j >= 0 || carry) {
10            if (i >= 0) carry += a[i--] - '0';
11            if (j >= 0) carry += b[j--] - '0';
12
13            res += carry % 2 + '0';
14            carry /= 2;
15        }
16
17        reverse(begin(res), end(res));
18        return res;        
19    }
20};