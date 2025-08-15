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

    bool inorder(TreeNode*root , int sum,int targetSum){
        if(root==NULL)return false;

        sum+=root->val;

        if(!root->right && !root->left){
            if(sum==targetSum)return true;
            return false;
        }
        bool leftsum=inorder(root->left,sum,targetSum);
        bool rightsum=inorder(root->right,sum,targetSum);

        return leftsum|| rightsum;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;

        bool res=inorder(root,sum,targetSum);
        return res; 
        
    }
};