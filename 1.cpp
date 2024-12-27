#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
private:
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        traverse(node->left, result);  // Visit left subtree
        result.push_back(node->val);  // Visit root
        traverse(node->right, result); // Visit right subtree
    }
};

int main() {
    // Example: Tree = [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    // Output: 1 3 2

    return 0;
}
