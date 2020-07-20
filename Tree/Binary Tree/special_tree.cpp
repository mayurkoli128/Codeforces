//Construct a special tree from given preorder traversal

#include "./header.hh"

TreeNode* specialTree(int* pre, char* preLN, int size, int& index, TreeNode* root) {
    if(size == index)   return nullptr;

    root = new TreeNode(pre[index]);

    if(preLN[index] == 'N') {
        index++;
        root->left = specialTree(pre, preLN, size, index, root->left);
        index++;
        root->right = specialTree(pre, preLN, size, index, root->right);
    }

    return root;
}
void traverse(TreeNode* root) {
    if(root) {
        traverse(root->left);
        traverse(root->right);
        cout << root->val << " ";
    }
}
int main() {
    TreeNode* root = nullptr;
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int index = 0;
    root = specialTree(pre, preLN, 5, index, root);
    traverse(root);
    return 0;
}