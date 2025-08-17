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
    bool recursion(TreeNode*root,int targetSum,int sum){
        if(root==NULL)return false;

        sum+=root->val;


        if(!root->left && !root->right){
            if(sum==targetSum){
                return true;
            }
            return false;
        }
        bool leftsum=recursion(root->left,targetSum,sum);
        bool rightsum=recursion(root->right,targetSum,sum);

        return leftsum|| rightsum;
        



    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;

        return recursion(root,targetSum,sum);


        
    }
};