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
 int getindex(vector<int>& inorder,int element){
    for(int i=0;i<inorder.size();i++){
        if(element==inorder[i]){
            return i;
        }
    }
    return -1;
   }
   TreeNode* buildtree(vector<int>& inorder, vector<int>& postorder,int &postidx,int instidx, int inendidx){
       if(postidx<0){
        return NULL;
       }
       if(instidx>inendidx){
        return NULL;
       }
       int element = postorder[postidx];
       postidx--;
       TreeNode* root = new  TreeNode(element);
       int inorderidx = getindex(inorder,element);
       root->right = buildtree(inorder,postorder,postidx,inorderidx+1,inendidx);
       root->left = buildtree(inorder,postorder,postidx,instidx,inorderidx-1);
     return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = postorder.size()-1;
        int instidx = 0;
        int inendidx = inorder.size()-1;
        return buildtree(inorder,postorder,postidx,instidx,inendidx);



    }
};