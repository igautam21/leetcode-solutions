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
    void traverse(TreeNode *node,int level,vector<pair<int,int>>&ds){
        if(!node) return;
        if(ds.size()==level) ds.push_back({node->val,level});
        traverse(node->right,level+1,ds);
        traverse(node->left,level+1,ds);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<pair<int,int>>ds;
        traverse(root,0,ds);
        vector<int>ans;
        for(auto x:ds){
            ans.push_back(x.first);
        }
        return ans;
    }
};