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
    pair<bool,int>check(TreeNode* root){
        if(root==NULL) return {true,0};
        pair<bool,int>left=check(root->left);
        pair<bool,int>right=check(root->right);
        int height=1+max(left.second,right.second);
        if(abs(left.second-right.second)>1) return {false,1e9};
        if(left.first && right.first)
        return {true,height};
        return {false,1e9};

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        pair<bool,int>ans=check(root);
        return ans.first;
    }
};