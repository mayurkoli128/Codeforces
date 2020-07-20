// vertical sum

#include "./header.hh"

class Solution {
vector<int> result;
public :
    void helper(TreeNode* root, map<int, vector<int>>& map, int key) {
        if(root == nullptr) return ;

        map[key].push_back(root->val);

        helper(root->left, map, key - 1);
        helper(root->right, map, key + 1);
    }
    vector<int> verticalSum(TreeNode* root) {
        map<int, vector<int>> map;
        helper(root, map, 0);

        for(auto mapEle : map) {
            auto vec = mapEle.second;
            int sum = 0;
            for(int i = 0; i < vec.size(); ++i) {
                sum += vec[i];
            }
            result.push_back(sum);
        }
        return result;
    }
};
int main() {
    TreeNode* root; 
    //Sample root..
    root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution s;
    auto result = s.verticalSum(root);

    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    } 
    return 0;
}