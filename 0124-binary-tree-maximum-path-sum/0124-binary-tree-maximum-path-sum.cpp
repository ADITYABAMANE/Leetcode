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
    int recursive(TreeNode*node,int &res){

        if(node==NULL)return 0;

        int leftsum=max(0, recursive(node->left,res));
        int rightsum=max(0, recursive(node->right,res));

        res=max(res,node->val+leftsum+rightsum);

        return node->val+max(leftsum,rightsum);


    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)return 0;
        int res=INT_MIN;

        recursive(root,res);

        return res;
        
    }
};