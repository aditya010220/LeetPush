1class Solution {
2public:
3    int len;
4    int toInt(string& nums){
5        int x=0;
6        for(char c: nums){
7            x=(x<<1)+(c-'0');
8        }
9        return x;
10    }
11    string findDifferentBinaryString(vector<string>& nums) {
12        len=nums[0].size();
13        vector<bool> hasX(1<<len, 0);
14
15        for(auto& x:  nums)
16            hasX[toInt(x)]=1;
17        int N=0;//find N
18        for(; N<(1<<len) && hasX[N]; N++);
19    //    cout<<N<<endl;
20        string ans=string(len, '0');
21        for(int i=len-1; i>=0 && N>0; i--){
22            ans[i]=(N&1)+'0';
23            N>>=1;
24        }
25        return ans;
26    }
27};
28auto init = []()
29{ 
30    ios::sync_with_stdio(0);
31    cin.tie(0);
32    cout.tie(0);
33    return 'c';
34}();