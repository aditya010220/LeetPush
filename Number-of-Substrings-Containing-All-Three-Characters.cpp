1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int i=0,j=0,ans=0;
5        int n=s.size();
6        unordered_map<char,int>mp;
7        while(j<s.size()){
8            mp[s[j]]++;
9            while(mp.size()==3){
10                ans+=(n-j);
11                mp[s[i]]--;
12                if(mp[s[i]]==0)mp.erase(s[i]);
13                i++;
14            }
15            j++;
16        }
17        return ans;
18    }
19};