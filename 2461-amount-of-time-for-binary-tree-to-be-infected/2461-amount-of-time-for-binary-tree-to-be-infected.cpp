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
    void buildgraph(TreeNode* node, map<int,vector<int>>&adj){
       

        if(node==NULL)return ;

        if(node->left){
           adj[node->val].push_back(node->left->val);
           adj[node->left->val].push_back(node->val);
        }
        if(node->right){
           adj[node->val].push_back(node->right->val);
           adj[node->right->val].push_back(node->val);
        }
        buildgraph(node->left,adj);
        buildgraph(node->right,adj);





        

    }





    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>>adj;
        buildgraph(root,adj);
        int cnt=-1;
        set<int>vis;
        queue<int>q;
        q.push(start);
        vis.insert(start);
       

        while(!q.empty()){
            int n=q.size();
            cnt++;

            for(int i=0;i<n;i++){
                int num=q.front();
                q.pop();

                for(auto it:adj[num]){
                    if(!vis.count(it)){
                        vis.insert(it);
                        q.push(it);
                    }
                }

            }



           

        }
        return cnt;
        
        
    }
};