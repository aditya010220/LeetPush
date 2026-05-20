1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        uint64_t maskA = 0, maskB = 0;
5
6        for (uint8_t i = 0; i < A.size(); i++) {
7            maskA |= 1ULL << A[i];
8            maskB |= 1ULL << B[i];
9            B[i] = __builtin_popcountll(maskA & maskB);
10        }
11
12        return B;
13    }
14};