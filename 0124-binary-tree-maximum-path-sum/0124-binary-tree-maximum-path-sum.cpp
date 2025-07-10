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
    int r(TreeNode* node,int &ans){
        if(node==NULL)return 0;

        int leftsum=max(0,r(node->left,ans));
        int rightsum=max(0,r(node->right,ans));


        ans=max(ans,node->val+leftsum+rightsum);

        return  node->val+max(leftsum,rightsum);



    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=INT_MIN;

        r(root,ans);

        return ans;
        
    }
};