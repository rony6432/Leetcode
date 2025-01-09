/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode*root,long max,long min){
        if(root==NULL) return true;
        bool left=check(root->left,root->val,min);
        bool right=check(root->right,max,root->val);
        return (left && right && root->val< max && root->val>min);
    }
    bool isValidBST(TreeNode* root) {
        long max=1e10;
        long min=-1e10;
        return check(root,max,min);
    }
};