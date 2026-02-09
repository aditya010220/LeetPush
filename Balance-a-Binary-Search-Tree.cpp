1class Solution {
2public:
3    void inorder(TreeNode* node, vector<int>& vals) {
4        if(!node) return;
5        inorder(node->left, vals);
6        vals.push_back(node->val);
7        inorder(node->right, vals);
8    }
9    TreeNode* build(const vector<int>& vals, int l, int r) {
10        if(l > r) return nullptr;
11        int mid = (l + r) / 2;
12        TreeNode* node = new TreeNode(vals[mid]);
13        node->left  = build(vals, l, mid - 1);
14        node->right = build(vals, mid + 1, r);
15        return node;
16    }
17    TreeNode* balanceBST(TreeNode* root) {
18        vector<int> vals;
19        inorder(root, vals);
20        return build(vals, 0, (int)vals.size() - 1);
21    }
22};