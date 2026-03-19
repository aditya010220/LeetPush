1#include <iostream>
2#include <string>
3using namespace std;
4
5class Solution {
6public:
7    int myAtoi(string s) {
8        int i = 0, sign = 1;
9        long res = 0; // Using long to handle overflow cases
10
11        // Trim leading spaces
12        while (i < s.size() && s[i] == ' ') i++;
13        if (i == s.size()) return 0;
14
15        // Check for sign
16        if (s[i] == '-') { sign = -1; i++; }
17        else if (s[i] == '+') i++;
18
19        // Process numerical characters
20        while (i < s.size() && isdigit(s[i])) {
21            res = res * 10 + (s[i] - '0');
22
23            // Handle overflow
24            if (sign * res > INT_MAX) return INT_MAX;
25            if (sign * res < INT_MIN) return INT_MIN;
26
27            i++;
28        }
29
30        return (int)(sign * res);
31    }
32};