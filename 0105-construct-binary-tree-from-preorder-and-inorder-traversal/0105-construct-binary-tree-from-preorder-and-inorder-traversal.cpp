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
    int getidx(vector<int>& inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &preorderidx,int instidx,int inendidx ){
        if(preorderidx>preorder.size()-1){
            return NULL;
        }
        if(instidx>inendidx){
            return NULL;
        }
        int element = preorder[preorderidx];
        preorderidx++;
        TreeNode* root = new TreeNode(element);
        int idx = getidx(inorder,element);
        root->left = solve(preorder,inorder,preorderidx,instidx,idx-1);
        root->right = solve(preorder,inorder,preorderidx,idx+1,inendidx);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderidx=0;
        int instidx=0;
        int inendidx=inorder.size()-1;
        return solve(preorder,inorder,preorderidx,instidx,inendidx);
    }
};