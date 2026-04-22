1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
4        vector<string> ans;
5        const int qz=queries.size(), sz=queries[0].size();
6        for(int j=0; j<qz; j++){
7            const string& q=queries[j];
8            for(const string& d: dictionary){
9                int diff=0;
10                for(int i=0; i<sz; i++){
11                    diff+=q[i]!=d[i];
12                    if (diff>2) break;
13                }
14                if (diff<=2) {
15                    ans.push_back(q); 
16                    break;
17                }  
18            }
19        }
20        return ans;
21    }
22};