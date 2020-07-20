#include "header.hh"

TreeNode* flatten(TreeNode* root) {
    if(root == nullptr) return nullptr;

    flatten(root->left);
    flatten(root->right);

    if(root->left) {
        TreeNode* subtree = root->left;

        while(subtree->right) {
            subtree = subtree->right;
        }
        subtree->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
    return root;
}
void traverse(TreeNode* root) {
    while (root)
    {
        std :: cout << root->val << " ";
        root = root->right;
    }
}
int main() {

    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(10);
    root->left->left = new TreeNode(9);
    root->left->left->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(12);
    root->right->right->left = new TreeNode(13);
    root->right->right->left->left = new TreeNode(14);
    flatten(root);
    traverse(root);
    return 0;
}