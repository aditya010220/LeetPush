1class Solution {
2public:
3
4    struct Node {
5        int child[26];
6        int idx;
7
8        Node() {
9            memset(child, -1, sizeof(child));
10            idx = -1;
11        }
12    };
13
14    vector<Node> trie;
15
16    // update best index according to:
17    // 1. smaller length
18    // 2. earlier index
19    void updateIndex(int &storedIdx,int newIdx,vector<string>& wordsContainer) {
20        if(storedIdx == -1) {
21            storedIdx = newIdx;
22            return;
23        }
24
25        int oldLen =wordsContainer[storedIdx].size();
26        int newLen =wordsContainer[newIdx].size();
27
28        if(newLen < oldLen) {
29            storedIdx = newIdx;
30        }
31        else if(newLen == oldLen && newIdx < storedIdx) {
32            storedIdx = newIdx;
33        }
34    }
35
36    vector<int> stringIndices(vector<string>& wordsContainer,vector<string>& wordsQuery) {
37        trie.push_back(Node());
38
39        // build reverse trie
40        for(int i = 0;i < wordsContainer.size();i++) {
41            string word = wordsContainer[i];
42            reverse(word.begin(),word.end());
43
44            int node = 0;
45
46            // update root answer also
47            updateIndex(trie[node].idx,i,wordsContainer);
48
49            for(char ch : word) {
50                int c = ch - 'a';
51
52                if(trie[node].child[c] == -1) {
53                    trie[node].child[c] = trie.size(); //index of the new node
54                    //child['a'] = 5, means go to trie[5]
55                    trie.push_back(Node());
56                }
57
58                node = trie[node].child[c];
59                updateIndex(trie[node].idx,i,wordsContainer);
60            }
61        }
62
63        vector<int> ans;
64
65        // process queries
66        for(string query : wordsQuery) {
67            reverse(query.begin(),query.end());
68
69            int node = 0;
70
71            for(char ch : query) {
72                int c = ch - 'a';
73
74                if(trie[node].child[c] == -1) {
75                    break;
76                }
77                node = trie[node].child[c];
78            }
79
80            ans.push_back(trie[node].idx);
81        }
82
83        return ans;
84    }
85};