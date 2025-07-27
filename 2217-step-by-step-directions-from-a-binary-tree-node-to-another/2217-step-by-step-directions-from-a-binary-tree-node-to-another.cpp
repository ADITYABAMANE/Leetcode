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

   bool pathi(TreeNode*adi, int target,string &path
         ){

            if(adi==NULL){
                return false;
            }
            if(adi->val==target){
                return true;
            }
            ///exploring the left subtree
            path.push_back('L');
            if(pathi(adi->left,target,path)==true){
                return true;
            }

            path.pop_back();

             ///exploring the left subtree
            path.push_back('R');
            if(pathi(adi->right,target,path)==true){
                return true;
            }

            path.pop_back();

            return false;



            




   }

    TreeNode* findLCA(TreeNode* node, int p, int q){
        if(node==NULL || node->val==p || node->val==q){
            return node;
        }

        TreeNode*left=findLCA(node->left,p,q);
        TreeNode* right= findLCA(node->right,p,q);

        if(!left){
            return right;
        }
        else if(!right){
            return left;
        }
        else{
            return node;
        }



    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode*LCA = findLCA(root,startValue , destValue);

        string lca_to_src="";
        string lca_to_des="";
        string res="";

        pathi(LCA,startValue , lca_to_src );
        pathi(LCA,destValue , lca_to_des);


        for(int i=0;i<lca_to_src.length();i++){
            res+='U';
        }

        res+=lca_to_des;


        return res;
        

        
    }
};