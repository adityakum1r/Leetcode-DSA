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
   void solve(TreeNode* root,int currsum,int &ans){
    //base case
    if(!root){
        return ;
    }
    currsum=currsum*10+root->val;
    if(!root->left && !root->right){
        ans+=currsum;
    }
    solve(root->left,currsum,ans);
    solve(root->right,currsum,ans);
    
    }
   
    int sumNumbers(TreeNode* root) {
      int currsum=0;
      int ans=0;
     solve(root,currsum,ans);
     return ans;   
    }
    
};