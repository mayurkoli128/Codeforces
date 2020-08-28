#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;

    TreeNode(int val) : val(val) {
        left = right = nullptr;
    }
};

// int height(TreeNode* root) {
//     if(root == nullptr) return -1;

//     return 1 + max(height(root->left), height(root->right));
// }
// void traversal(TreeNode* root, int level, bool flag) {
//     if(root == nullptr) return ;
    
//     if(level == 0) {
//         cout << root->val << " ";
//         return ;
//     }

//     if(flag) {
//         traversal(root->left, level - 1, flag);
//         traversal(root->right, level - 1, flag);
//     } else {
//         traversal(root->right, level - 1, flag);
//         traversal(root->left, level - 1, flag);
//     }
// }
// void recursive(TreeNode* root) {
//     int h = height(root);
//     bool flag = true;
//     for(int i = 0; i <= h; ++i) {
//         traversal(root, i, flag);
//         flag = flag ? false : true;
//     }
//     return ;
// }
// void traversal(TreeNode* root) {
//     queue<TreeNode*> q;
//     q.push(root);

// int height(TreeNode* root) {
//     if(root == nullptr) return -1;

//     return 1 + max(height(root->left), height(root->right));
// }
// void traversal(TreeNode* root, int level, bool flag) {
//     if(root == nullptr) return ;
    
//     if(level == 0) {
//         cout << root->val << " ";
//         return ;
//     }

//     if(flag) {
//         traversal(root->left, level - 1, flag);
//         traversal(root->right, level - 1, flag);
//     } else {
//         traversal(root->right, level - 1, flag);
//         traversal(root->left, level - 1, flag);
//     }
// }
// void recursive(TreeNode* root) {
//     int h = height(root);
//     bool flag = true;
//     for(int i = 0; i <= h; ++i) {
//         traversal(root, i, flag);
//         flag = flag ? false : true;
//     }
//     return ;
// }
// void traversal(TreeNode* root) {
//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty()) {
//         root = q.front();
//         q.pop();
//         cout << root->val << " ";

//         if(root->left)  q.push(root->left);
//         if(root->right)  q.push(root->right);
//     }

//     return ;
// } if(root->right)  q.push(root->right);
//     }

//     return ;
// }

void zigzag(TreeNode* root) {
    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        
        // push left to right
        while(!s1.empty()) {
            root = s1.top();
            s1.pop();
            cout << root->val << " ";

            if(root->left) {
                s2.push(root->left);
            } 
            if(root->right) {
                s2.push(root->right);
            }
        }
        while(!s2.empty()) {
            root = s2.top();
            s2.pop();
            cout << root->val << " ";
            
            if(root->right) {
                s1.push(root->right);
            }
            if(root->left) {
                s1.push(root->left);
            } 
        }

    }
}

void post_order(TreeNode* root) {
    stack<TreeNode*> s;
    
    while (1) {
        
        while(root) {
            s.push(root);
            root = root->left;
        }

        if(s.empty())   break;

        root = s.top();
        if(root->right) {
            root = root->right;
        } else {
            cout << root->val << " ";
            s.pop();
            if(s.empty())   break;
            root = s.top();
            root = root->right;            
        }
    }
}
int dia = INT32_MIN;

int diameter(TreeNode* root) {
    if (root == nullptr)    return 0;

    int x = diameter(root->left);
    int y = diameter(root->right);

    dia = max(dia, 1 + x + y);
    return 1 + max(x, y);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(6);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(3);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(6);
    root->right->right->right->left = new TreeNode(10);

    // traversal(root);
    // recursive(root);
    // zigzag(root);

    // post_order(root);
    diameter(root);
    cout << dia ;
    return 0;
}