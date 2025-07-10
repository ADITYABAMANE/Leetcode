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
    TreeNode* build(vector<int>& nums, int start, int end ){

        int n=nums.size();

        

        int maxidx = start;
        if(start> end)return NULL;
        for(int i=start;i<=end;i++){
            if(nums[i]>nums[maxidx]){
                maxidx=i;



            }
        }
        TreeNode*node=new TreeNode(nums[maxidx]);

       node->left= build(nums,start,maxidx-1 );
        node->right= build(nums,maxidx+1,end );

        return node;




     }




    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       
        return build(nums,0,nums.size()-1 );

        




       

        

        

        
    }
};