/// Deletion in BST...

#include "./header.hh"

TreeNode *findMin(TreeNode *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
TreeNode *deletion(TreeNode *root, int key)
{

    if (root == nullptr)
        return nullptr;

    if (root->val > key)
    {
        root->left = deletion(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = deletion(root->right, key);
    }
    else
    {
        // case 1 : when root has no children's...
        if (!root->left && !root->right)
        {
            delete root;
            root = nullptr;
        }
        // case 2: when root has either left or right...
        else if (root->left)
        {
            TreeNode *temp = root->left;
            delete root;
            root = temp;
        }
        else if(root->right) {
            TreeNode *temp = root->right;
            delete root;
            root = temp;  
        }
        // case 3: when root has both left and right...
        else
        {
            TreeNode *temp = findMin(root->right);
            root->val = temp->val;
            root->right = deletion(temp, temp->val);
        }
    }
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    root = insertion(root, 2);
    root = insertion(root, 5);
    root= insertion(root, 6);
    root = insertion(root, 9);

    traverse(root);
    std ::cout << "\n";
    root = deletion(root, 6);
    traverse(root);

    return 0;
}