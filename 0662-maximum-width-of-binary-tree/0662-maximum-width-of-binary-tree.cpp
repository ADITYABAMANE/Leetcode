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
        if(!root)return 0;
        queue<pair<TreeNode*,int>>q;//declaring a queue
        q.push({root,0});
        int maxw=0;
        
        while(!q.empty()){
            int n=q.size();


            int l=q.front().second;
            int r=q.back().second;
            maxw=max(maxw,r-l+1);

            while(n--){
                TreeNode*curr=q.front().first;
                long long idx=q.front().second;
                q.pop();

                if(curr->left!=NULL){
                    q.push({curr->left,2*idx+1});
                }
                 if(curr->right!=NULL){
                    q.push({curr->right,2*idx+2});
                }

}
}
        return maxw;




        
    }
};