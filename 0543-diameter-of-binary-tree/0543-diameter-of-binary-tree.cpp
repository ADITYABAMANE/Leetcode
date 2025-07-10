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

    int Recursion(TreeNode* node,int &res){
        if(node==NULL)return 0;

        int lh=Recursion(node->left,res);
        int rh=Recursion(node->right,res);

        res=max(res,lh+rh);
        return 1+max(lh,rh);



    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int res=INT_MIN;

        Recursion(root, res);

        return res;
        
    }
};