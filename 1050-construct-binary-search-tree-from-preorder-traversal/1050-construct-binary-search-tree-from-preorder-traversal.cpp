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
TreeNode*cal(vector<int>& arr,int &i,int b){
    if(i>=arr.size() || arr[i]>b) return NULL;
    TreeNode*root=new TreeNode(arr[i++]);
    root->left=cal(arr,i,root->val);
    root->right=cal(arr,i,b);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i=0;
        return cal(arr,i,INT_MAX);
    }
};