1class Solution {
2public:
3    string getHappyString(int n, int k) {
4
5        int total = 3 * (1<<(n-1));
6        if(k>total) return "";
7
8        k--;
9        string res="";
10        char last='\0';
11
12        for(int pos=0;pos<n;pos++){
13
14            int branch=1<<(n-pos-1);
15
16            vector<char> choices;
17            for(char c:{'a','b','c'})
18                if(c!=last) choices.push_back(c);
19
20            int idx=k/branch;
21            res+=choices[idx];
22            last=choices[idx];
23            k%=branch;
24        }
25
26        return res;
27    }
28};