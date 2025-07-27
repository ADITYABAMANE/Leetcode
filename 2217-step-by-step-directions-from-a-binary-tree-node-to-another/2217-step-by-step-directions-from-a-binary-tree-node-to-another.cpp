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

     bool findpath(TreeNode* node, int target, string &path){

        if(node==NULL){
            return false;
        }
        if(node->val==target){
            return true;
        }
        //exploring left 

        path.push_back('L');

        if(findpath(node->left,target,path )==true){
            return true;
        }
        path.pop_back();

        //exploring the right
        path.push_back('R');
        if(findpath(node->right,target,path )==true){
            return true;
        }

        path.pop_back();




        return false;
        




     }



    string getDirections(TreeNode* root, int startValue, int destValue) {

        string rts="";
        string rtd="";

        findpath(root,startValue,rts );
        findpath(root,destValue,rtd );

        int l=0;
        while(l<rts.length() && l<rtd.length() && rts[l]==rtd[l]){
           l++;
        }

        string res="";
        for(int i=l;i<rts.length();i++){
            res.push_back('U');
        }
        for(int i=l;i<rtd.length();i++){
            res+=rtd[i];
        }
        return res;

        
    }
};