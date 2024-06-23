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
    TreeNode*prev;
    TreeNode*first;
    TreeNode*mid;
    TreeNode*last;
    void inorder(TreeNode*node){
        if(node==NULL) return;
        inorder(node->left);
        if(prev!=NULL &&(prev->val>node->val)){
            if(first==NULL){
                first=prev;
                mid=node;
            }
            else{
                last=node;
            }
        }
        prev=node;
        inorder(node->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=mid=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && mid) swap(first->val,mid->val);
    }
};