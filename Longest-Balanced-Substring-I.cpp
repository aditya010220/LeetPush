1int freq[26]={0};
2class Solution {
3public:
4    static int longestBalanced(string& s) {
5        int cnt=1, n=s.size();
6        for(int l=0; l<n; l++){
7            memset(freq, 0, sizeof(freq));
8            int uniq=0, maxF=0, cntMax=0;
9            for(int r=l; r<n; r++){
10                int f=++freq[s[r]-'a'];
11                uniq+=(f==1);
12                if (f>maxF){ maxF=f; cntMax=1; }
13                else if (f==maxF) cntMax++;
14                if (uniq==cntMax) 
15                    cnt=max(cnt, r-l+1);
16            }
17        }
18        return cnt;
19    }
20};