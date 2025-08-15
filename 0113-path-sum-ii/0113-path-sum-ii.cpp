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
    vector<vector<int>>res;
    void fill(TreeNode* root, int targetSum,vector<int>temp,int sum){
        if(!root)return ;

        sum+=root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right){
            if(sum==targetSum){
                res.push_back(temp);
            }

        }
        fill(root->left,targetSum,temp,sum);
        fill(root->right,targetSum,temp,sum);



        temp.pop_back();


    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;


        fill(root,targetSum,temp,sum);
        return res;
        
    }
};