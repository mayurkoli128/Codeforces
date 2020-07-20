// Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
// Expected Auxiliary Space: O(Height of BST1 + Height of BST2).

#include "./header.hh"
#include <stack>

class Solution {
public :
    void insertLeft(TreeNode* root, stack<TreeNode*>& s) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
    vector<int> merge2BST(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> result;

        insertLeft(root1, s1);
        insertLeft(root2, s2);

        while(!s1.empty() && !s2.empty()) {
            TreeNode* temp1 = s1.top();
            TreeNode* temp2 = s2.top();

            if(temp1->val > temp2->val) {
                result.push_back(temp2->val);
                s2.pop();
                insertLeft(temp2->right, s2);
            }else {
                result.push_back(temp1->val);
                s1.pop();
                insertLeft(temp1->right, s1);
            }
        }
        
        while(!s1.empty()) {
            TreeNode* temp = s1.top();
            result.push_back(temp->val);
            s1.pop();
            insertLeft(temp->right, s1);
        }
        while(!s2.empty()) {
            TreeNode* temp = s2.top();
            result.push_back(temp->val);
            s2.pop();
            insertLeft(temp->right, s2);
        }
        return result;
    }
};
void traverse(TreeNode* root) {
    if(root) {
        traverse(root->left);
        cout << root->val << " ";
        traverse(root->right);
    }
}
int main() {
    TreeNode* root1 = nullptr, *root2 = nullptr;

    // root1
    root1 = new TreeNode(10);
    root1->right = new TreeNode(14);
    root1->right->left = new TreeNode(12);
    root1->right->left->right = new TreeNode(13);
    root1->right->right = new TreeNode(18);
    root1->right->right->left = new TreeNode(15);
    root1->right->right->left->right = new TreeNode(17);
    root1->right->right->left->right->left = new TreeNode(16);
    root1->left = new TreeNode(6);
    root1->left->right = new TreeNode(7);
    root1->left->right->right = new TreeNode(8);
    root1->left->left = new TreeNode(4);
    root1->left->left->right = new TreeNode(5);
    root1->left->left->left = new TreeNode(2);
    root1->left->left->left->right = new TreeNode(3);

    // root2

    root2 = new TreeNode(10);
    root2->right = new TreeNode(20);
    root2->left = new TreeNode(7);
    root2->left->right = new TreeNode(9);
    root2->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(5);
    root2->left->left->right->right = new TreeNode(6);

    Solution s;
    auto vec = s.merge2BST(root1, root2);
    for(int ele : vec) {
        cout << ele << " ";
    }
    return 0;
}