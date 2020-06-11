// Construct Binary Tree from Preorder and Inorder Traversal

#include "./header.hh"

TreeNode* solve(int* preorder, int pStart, int pEnd, int* inorder, int iStart, int iEnd, TreeNode* root) {
    // base case..

    if(iStart > iEnd)   return nullptr;

    int data = preorder[pStart];

    root = new TreeNode(data);

    int index = find(inorder, inorder + iEnd, data) - inorder;
    // solve for left
    root->left = solve(preorder, pStart + 1, pStart + (index - iStart), inorder, iStart, index - 1, root->left);
    // solve for right
    root->right = solve(preorder, pStart + (index - iStart) + 1, pEnd, inorder, index + 1, iEnd, root->right);

    return root;
}
void traversal(TreeNode* root) {
    if(root == nullptr) return;

    traversal(root->left);
    traversal(root->right);
    cout << root->val << " ";
}
int main() {
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};
    int size = 5;

    traversal(solve(preorder, 0, size-1, inorder, 0, size-1, nullptr));
    return 0;
}