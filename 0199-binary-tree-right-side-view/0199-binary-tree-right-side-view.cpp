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

    void preorder(TreeNode* node,int depth,vector<int>&res){
        if(node==NULL)return;


        if(res.size()<depth){
            res.push_back(node->val);
        }
         preorder(node->right,depth+1,res);
        preorder(node->left,depth+1,res);


        

        

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
       
        int level=0;
        

        preorder(root,1,res);


        return res;


        







        

        
    }
};