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
    void preorder(TreeNode* node,vector<int>&res, int level){

        if(node==NULL)return ;
        if(res.size()<level){
            res.push_back(node->val);

        }
        preorder(node->right,res, level+1);
        preorder(node->left,res, level+1);


    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;


        preorder(root,res, 1);

        return res;

        
    }
};