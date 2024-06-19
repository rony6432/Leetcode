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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxi=0;
        while(!q.empty()){
              int m=q.front().second;
              int size=q.size();
              int f,l;
              for(int i=0;i<size;i++){
                TreeNode*node=q.front().first;
                long long leb=q.front().second-m;
                q.pop();
                if(i==0)f=leb;
                if(i==size-1) l=leb;
                if(node->left) q.push({node->left,2*leb+1});
                if(node->right) q.push({node->right,2*leb+2});
              }
              maxi=max(maxi,(l-f+1));
        }
        return maxi;
    }
};