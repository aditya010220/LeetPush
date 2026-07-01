1class Solution {
2public:
3    int hammingWeight(int n) {
4        int count =0;
5    while(n){
6        n= n&(n-1);
7        count++;
8    }   
9    return count; 
10    }
11};