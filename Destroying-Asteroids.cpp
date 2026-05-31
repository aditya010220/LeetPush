1unsigned freq[100001]={0};
2class Solution {
3public:
4    static bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
5        unsigned xmax=0, xmin=1e5;
6        for(unsigned x: asteroids){
7            freq[x]++;
8            xmin=min(xmin, x);
9            xmax=max(xmax, x);
10        }
11        long long planet=mass;// careful for overflow
12        for(int x=xmin; x<=xmax; x++){
13            if (freq[x]==0) continue;
14            if (x>planet) {
15                memset(freq+x, 0, (xmax-x+1)*sizeof(unsigned));
16                return 0;
17            }
18            planet+=(long long)x*freq[x];
19            freq[x]=0;
20        }
21        return 1;
22    }
23};
24auto init = []() {
25    ios::sync_with_stdio(false);
26    cin.tie(nullptr);
27    cout.tie(nullptr);
28    return 'c';
29}();