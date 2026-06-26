1class Solution {
2public:
3
4double solve(double x , long long n){
5    if(n==0) return 1;
6    if(n%2==0){
7        return solve(x*x,n/2);
8    }
9    else{
10        return x*solve(x*x,(n-1)/2);
11    }
12}
13    double myPow(double x, int n) {
14        long long N =n;
15        if(N>=0){
16            return solve(x,N);
17        }
18        return solve(1/x,-N);
19    }
20};