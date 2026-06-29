1class Solution {
2    struct Node {
3        Node* c[26]{};
4        Node* f{};
5        Node* l{};
6        int n = 0;
7    };
8
9    static constexpr int mx = 10005;
10
11public:
12    int numOfStrings(vector<string>& patterns, string word) {
13        Node* root = new Node();
14        
15        for (auto& p : patterns) {
16            Node* curr = root;
17            
18            for (int i = 0; i < p.size(); i++) {
19                int x = p[i] - 97;
20                
21                if (!curr->c[x])
22                    curr->c[x] = new Node();
23                    
24                curr = curr->c[x];
25            }
26            
27            curr->n++;
28        }
29        
30        Node* q[mx];
31        int hd = 0;
32        int tl = 0;
33        
34        for (int i = 0; i < 26; i++) {
35            if (!root->c[i]) {
36                root->c[i] = root;
37                continue;
38            }
39            
40            root->c[i]->f = root;
41            root->c[i]->l = nullptr;
42            q[tl] = root->c[i];
43            tl++;
44        }
45        
46        while (hd < tl) {
47            Node* curr = q[hd];
48            hd++;
49            
50            for (int i = 0; i < 26; i++) {
51                if (!curr->c[i]) {
52                    curr->c[i] = curr->f->c[i];
53                    continue;
54                }
55                
56                curr->c[i]->f = curr->f->c[i];
57                
58                if (!curr->c[i]->f->n)
59                    curr->c[i]->l = curr->c[i]->f->l;
60                else
61                    curr->c[i]->l = curr->c[i]->f;
62                    
63                q[tl] = curr->c[i];
64                tl++;
65            }
66        }
67        
68        Node* curr = root;
69        int res = 0;
70        
71        for (auto& w : word) {
72            int x = w - 97;
73            curr = curr->c[x];
74            
75            Node* m = curr;
76            
77            while (m) {
78                res += m->n;
79                m->n = 0;
80                
81                Node* tmp = m->l;
82                m->l = nullptr;
83                m = tmp;
84            }
85        }
86        
87        return res;
88    }
89};