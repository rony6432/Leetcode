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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }

    TreeNode* build(vector<int>& preorder,int pre0,int pren,vector<int>& inorder,int in0,int inn,map<int,int>&mp){
                          if(pre0>pren || in0>inn) return NULL;

                          TreeNode* root=new TreeNode(preorder[pre0]);


                          int endin=mp[root->val];
                          int dif=endin-in0;
                          root->left=build(preorder,pre0+1,pre0+dif,inorder,in0,endin-1,mp);
                          root->right=build(preorder,pre0+dif+1,pren,inorder,endin+1,inn,mp);
                          return root;
    }
};