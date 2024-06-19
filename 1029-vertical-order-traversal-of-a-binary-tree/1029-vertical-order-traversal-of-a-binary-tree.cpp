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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        vector<vector<int>>v;
        if(root==NULL)return v;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode*f=q.front().first;
            int vleb=q.front().second.first;
            int hleb=q.front().second.second;
            mp[vleb].push_back({hleb,f->val});
            q.pop();
            if(f->left)q.push({f->left,{vleb-1,hleb+1}});
            if(f->right)q.push({f->right,{vleb+1,hleb+1}});

        }
        for(auto it:mp){
          vector<int>temp;
          sort(it.second.begin(),it.second.end());
          for(auto i:it.second){
                     temp.push_back(i.second);
                 }
                 v.push_back(temp);
        } 
        return v;

    }
};