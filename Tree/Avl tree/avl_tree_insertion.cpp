// Balanced binary search tree...

#include "./header.hh"

int height(TreeNode* root) {
    if(root == nullptr) return -1;

    return root->height;
}
TreeNode* singleRightRotation(TreeNode* root) {
    TreeNode* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(root->right));
    return temp;
}
TreeNode* singleLeftRotation(TreeNode* root) {
    TreeNode* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(root->right));
    return temp;
}

TreeNode* insertion(TreeNode* root, int val) {
    if(root == nullptr)     return new TreeNode(val);

    if(val <= root->val) {
        root->left = insertion(root->left, val);
    }
    else root->right = insertion(root->right, val);

    root->height = 1 + max(height(root->left), height(root->right));

    int balanceFactor = height(root->left) - height(root->right);
    // single left ro
    // root is balance if balanceFactor = {-1, 0, 1}
    
    // LL
    if(balanceFactor > 1 && root->left->val >= val) {
        return singleRightRotation(root);
    }
    // RR
    else if(balanceFactor < -1 && root->right->val < val) {
        return singleLeftRotation(root);
    }
    // LR
    else if(balanceFactor > 1 && root->left->val < val) {
        root->left = singleLeftRotation(root->left);
        return singleRightRotation(root);
    }
    //RL
    else if(balanceFactor < -1 && root->right->val >= val) {
        root->right = singleRightRotation(root->right);
        return singleLeftRotation(root);
    }
    return root;
}
void traversal(TreeNode* root) {
    if(root) {
        traversal(root->left);
        cout << root-> val << " " << root->height << " \n";
        traversal(root->right);
    }
}
int main() {
    TreeNode* root = nullptr;
    int arr[] = {5, 3, 9, 2, 4, 4, 8, 10, 1, 7, 6};

    for(int i = 0; i < 10; ++i) {
        root = insertion(root, arr[i]);
    } 
    traversal(root);
    return 0;
} 