1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        const int n=nums.size();
5        const auto [Dmin, Dmax]=minmax(start, (n-1)-start);
6        int d=0;
7        for(; d<=Dmin; d++){
8            const int x=nums[start-d], y=nums[start+d];
9            if (x==target || y==target) return d;
10        }
11        int sgn=(start==Dmin)?1:-1;
12        for(d=Dmin+1; d<=Dmax; d++){
13            const int x=nums[start+sgn*d];
14            if (x==target) return d;
15        }
16        return -1;// never reach
17    }
18};