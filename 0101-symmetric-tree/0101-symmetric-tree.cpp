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
   bool check( TreeNode* leftchild,TreeNode* rightchild){
    if(leftchild==NULL && rightchild==NULL){
        return true;
    }
    if(leftchild==NULL || rightchild==NULL){
        return false;
    }
    if(leftchild->val!=rightchild->val){
        return false;
    }
    bool leftans = check(leftchild->left,rightchild->right);
    bool rightans = check(leftchild->right,rightchild->left);
    return (leftans && rightans);
   }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        TreeNode* leftchild = root->left;
        TreeNode* rightchild = root->right;
      return  check(leftchild,rightchild);
    }
};