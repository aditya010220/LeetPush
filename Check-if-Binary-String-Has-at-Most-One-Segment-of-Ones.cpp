1class Solution {
2public:
3    bool checkOnesSegment(string& s) {
4        const int n=s.size();
5        int i0=s.find('0');
6        if (i0==-1) return 1;
7        int i1=s.find_last_of('1');
8        return i0>i1;
9    }
10};