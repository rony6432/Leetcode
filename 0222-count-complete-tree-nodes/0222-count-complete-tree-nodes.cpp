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
    int lh(TreeNode* node){
        int hi=0;
        while(node){
            hi++;
            node=node->left;
        }
        return hi;
    }
    int rh(TreeNode* node){
        int hi=0;
        while(node){
            hi++;
            node=node->right;
        }
        return hi;
    }
    int countNodes(TreeNode* root) {
        int l=lh(root);
        int r=rh(root);

        if(l==r) return(1<<l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};