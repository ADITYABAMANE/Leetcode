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
    int widthOfBinaryTree(TreeNode* root) {
        int maxw=0;
        if(!root){
            return 0;
        }


        queue<pair<TreeNode*, int>>q;

        q.push({root,0});

        while(!q.empty()){
            int l=q.front().second;
            int r=q.back().second;
            maxw=max(maxw,r-l+1);

            int n=q.size();
            while(n--){


                TreeNode* node=q.front().first;
                long long idx=q.front().second;

                q.pop();
                if(node->left!=NULL){
                    q.push({node->left, 2*idx+1});
                }
                if(node->right!=NULL){
                    q.push({node->right, 2*idx+2});
                }


                





            }




            
        }
        return maxw;





        
    }
};