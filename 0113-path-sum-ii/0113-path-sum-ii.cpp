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

    void fill(TreeNode* root, int targetSum, vector<vector<int>>&res,int sum,vector<int>&temp){
        if(root==NULL)return ;
        sum+=root->val;
        temp.push_back(root->val);
        

        if(!root->left && !root->right){
            if(sum==targetSum){
                res.push_back(temp);
            }

        }
        fill(root->left,targetSum,res,sum,temp);
        fill(root->right,targetSum,res,sum,temp);


        temp.pop_back();






    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>temp;

        vector<vector<int>>res;

        fill(root,targetSum,res,sum,temp);

        return res;
        
    }
};