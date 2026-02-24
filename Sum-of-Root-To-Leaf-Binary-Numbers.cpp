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
14    int solve(TreeNode* root, int curr){
15        if(!root) return 0;
16
17        curr = curr*2 + root->val;
18
19        if(!root->left && !root->right)
20            return curr;
21
22        return solve(root->left, curr) + solve(root->right, curr);
23    }
24
25    int sumRootToLeaf(TreeNode* root) {
26        return solve(root, 0);
27    }
28};