// Custom Binary Search Tree Node class to avoid conflict with platform-defined TreeNode
class myNode {
public:
    int val;
    myNode* left;
    myNode* right;

    myNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;
    const int MAX = 1000;

    vector<long long> fact, inv_fact;

    // Fast exponentiation: computes a^b % mod
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    // Precomputes factorials and inverse factorials modulo mod
    void precompute() {
        fact.resize(MAX);
        inv_fact.resize(MAX);
        fact[0] = inv_fact[0] = 1;
        for (int i = 1; i < MAX; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            inv_fact[i] = power(fact[i], mod - 2); // Fermat's Little Theorem
        }
    }

    // Computes nCr % mod using precomputed factorials
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
    }

    // Recursively inserts a value into the BST
    void prepareTree(myNode* root, int val) {
        if (val < root->val) {
            if (root->left != nullptr) {
                prepareTree(root->left, val);
            } else {
                root->left = new myNode(val);
            }
        } else {
            if (root->right != nullptr) {
                prepareTree(root->right, val);
            } else {
                root->right = new myNode(val);
            }
        }
    }

    // Recursive function to count number of nodes and number of reorderings possible
    pair<int, int> fn(myNode* root) {
        if (root == nullptr) return {0, 1};
        if (root->left == nullptr && root->right == nullptr) return {1, 1};

        // Recursive results from left and right subtrees
        auto pf = fn(root->left);
        auto sf = fn(root->right);

        int total_child = pf.first + sf.first;

        // Combine left and right results
        long long cost = 1LL * pf.second * sf.second % mod;

        // Count ways to interleave left and right subtrees while preserving order
        long long more_cost = nCr(total_child, pf.first);

        // Final number of ways for this subtree
        long long final_cost = cost * more_cost % mod;

        return {total_child + 1, (int)final_cost};  // +1 to include current root
    }

    // Main function: Builds BST, computes result, subtracts 1 (excluding original ordering)
    int numOfWays(vector<int>& nums) {
        precompute();  // Setup factorials

        myNode* root = new myNode(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prepareTree(root, nums[i]);
        }

        auto ps = fn(root);
        return (ps.second - 1 + mod) % mod;  // Subtract 1 to exclude the original sequence
    }
};