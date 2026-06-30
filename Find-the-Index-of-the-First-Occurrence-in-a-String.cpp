1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        if(haystack.length()<needle.length()) return -1;
5
6        int n = haystack.length()-needle.length();
7        int m = needle.length();
8        for(int i =0;i<=n;i++){
9            if(haystack.substr(i,m)==needle){
10                return i;
11            }
12        }
13        return -1;
14    }
15};