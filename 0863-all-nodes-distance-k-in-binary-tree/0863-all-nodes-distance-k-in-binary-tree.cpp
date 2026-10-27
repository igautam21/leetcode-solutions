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
    void markParents(TreeNode *node,unordered_map<TreeNode*,TreeNode*>&pt,TreeNode* t){
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->left){
                pt[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                pt[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentTrack;
        markParents(root,parentTrack,target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        int currlevel=0;
        while(!q.empty()){
            int n=q.size();
            if(currlevel++==k) break;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentTrack.count(node) && !visited[parentTrack[node]]){
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};