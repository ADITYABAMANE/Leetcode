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
    void fill(TreeNode*node,int targetSum, vector<int>&temp,int sum){
        if(!node)return ;

        sum+=node->val;





        temp.push_back(node->val);
        if(!node->left && !node->right){
            if(sum==targetSum){
                res.push_back(temp);
            }
            


        }
        fill(node->left,targetSum,temp,sum);
        fill(node->right,targetSum,temp,sum);


        temp.pop_back();



        

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;
        fill(root,targetSum,temp,sum);

        return res;
        
    }
};