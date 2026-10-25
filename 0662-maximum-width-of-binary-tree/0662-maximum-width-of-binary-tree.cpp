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
        long long ans=0;
        if(!root) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            long long mn=q.front().second;
            int n=q.size();
            long long first,last;
            for(int i=0;i<n;i++){
                long long id=q.front().second-mn;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=id;
                if(i==n-1) last=id;
                if(node->left) q.push({node->left,2*id+1});
                if(node->right) q.push({node->right,2*id+2});
            }
            ans=max(ans,last-first+1);
        }
        return (int)ans;
    }
};