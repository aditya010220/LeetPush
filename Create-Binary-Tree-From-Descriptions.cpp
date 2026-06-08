1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* createBinaryTree(vector<vector<int>>& A) {
15        unordered_map<int, TreeNode*> nodes;
16        nodes.reserve(A.size() + 1);
17        int root = 0;
18
19        for (auto& d : A) {
20            int x = d[0], y = d[1], isLeft = d[2];
21            if (!nodes.contains(x)) {
22                nodes[x] = new TreeNode(x);
23                root ^= x;
24            }
25            if (!nodes.contains(y)) {
26                nodes[y] = new TreeNode(y);
27                root ^= y;
28            }
29
30            if (isLeft)
31                nodes[x]->left = nodes[y];
32            else
33                nodes[x]->right = nodes[y];
34            root ^= y;
35        }
36
37        return nodes[root];
38    }
39};