class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            if (preorder[i] < s.top()->val) {
                s.top()->left = node;
            } else {
                TreeNode* parent = nullptr;
                while (!s.empty() && preorder[i] > s.top()->val) {
                    parent = s.top();
                    s.pop();
                }
                parent->right = node;
            }
            s.push(node);
        }
        return root;
    }
};

