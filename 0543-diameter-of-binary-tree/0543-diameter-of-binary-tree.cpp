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

    int  actual_diameter(TreeNode* node,int &ans){
        if(node==NULL)return 0;

        int lh=actual_diameter(node->left,ans);
        int rh=actual_diameter(node->right,ans);

        ans=max(ans,lh+rh);

        return 1+max(lh,rh);
        


    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=INT_MIN;

        actual_diameter(root,ans);
        return ans;
        
    }
};