1class Solution {
2public:
3    inline static long long f(long long t, vector<int>& workerTimes){
4        long long x=0;
5        for(int w: workerTimes)
6            x+=(long long)((sqrt(1+8.0*t/w)-1)/2);
7        return x;
8    }
9    static long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
10        int wz=workerTimes.size();
11        if (wz==1)
12            return (long long)workerTimes[0]*mountainHeight*(mountainHeight+1)/2;
13        long long l=1, r=1e12*(long long)mountainHeight/wz;
14        while(l<r){
15            long long m=l+(r-l)/2;
16            long long x=f(m, workerTimes);
17            if(x>=mountainHeight) r=m;
18            else l=m+1;
19        }
20        return l;
21    }
22};