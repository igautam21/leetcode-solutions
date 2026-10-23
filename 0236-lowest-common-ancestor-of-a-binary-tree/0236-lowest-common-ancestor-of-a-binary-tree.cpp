/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getpath(TreeNode* node,vector<TreeNode*>&arr,TreeNode *t){
        if(!node) return false;
        arr.push_back(node);
        if(node==t) return true;
        if(getpath(node->left,arr,t) || getpath(node->right,arr,t)) return true;
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pp,pq;
        getpath(root,pp,p);
        getpath(root,pq,q);
        TreeNode *lca=nullptr;
        int n=min(pp.size(),pq.size());
        for(int i=0;i<n;i++){
            if(pp[i]!=pq[i]){
                break;
            }
            lca=pp[i];
        }
        return lca;
    }
};