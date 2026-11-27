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
    void markParents(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&par,TreeNode*& src,int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start) src=node;
            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right]=node;
                q.push(node->right);
            }
        }
    }
    int burn(TreeNode *src,unordered_map<TreeNode*,TreeNode*>&par){
        queue<TreeNode*>q;
        q.push(src);
        unordered_set<TreeNode*>vis;
        vis.insert(src);
        int time=-1;
        while(!q.empty()){
            int n=q.size();
            time++;
            while(n--){
                TreeNode *node=q.front();
                q.pop();
                for(auto x:{node->left,node->right,par[node]}){
                    if(x&& vis.insert(x).second)
                        q.push(x);
                }
            }
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        unordered_map<TreeNode*,TreeNode*>par;
        TreeNode* src=nullptr;
        markParents(root,par,src,start);
        return burn(src,par);
    }
};